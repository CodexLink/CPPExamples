from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
import uvicorn
import fastapi
import dotenv
import aiosmtplib
from email.message import EmailMessage # has to be specified.
import asyncio

env = dotenv.load_dotenv(
	dotenv.find_dotenv(filename=".env", raise_error_if_not_found=True)
)

import os

api_instance = fastapi.FastAPI()

@api_instance.on_event("startup")
async def startup(): # Wrapper for send_email.
	ensure = asyncio.create_task(send_email())
	await ensure

async def send_email():
	astmp_instance = aiosmtplib.SMTP(hostname="smtp.gmail.com", port=465, username=os.environ.get("from", None),password=os.environ.get("pwd", None), use_tls=True)

	print("Attempting to connect to GMail SMTP.")
	# https://stackoverflow.com/questions/10147455/how-to-send-an-email-with-gmail-as-provider-using-python
	await astmp_instance.connect()
	await astmp_instance.ehlo()

	print("Connected... Attempting to send some message.")

	# email_instance = EmailMessage()
	email_instance = MIMEMultipart("alternative")
	email_instance["From"] = os.environ.get("from", None)
	email_instance["To"] = os.environ.get("to", None)
	email_instance["Subject"] = "Test Email with aiostmplib with MIMEText"
	# email_instance.set_content("This is just a test. <a href='https://github.com/CodexLink'>Test is just a test, it just redirects to my github.</a>") # This does not render anything.

	html_message = MIMEText(
		"<html><body><h1>Sent via aiosmtplib</h1></body></html>This is just a test. <a href='https://github.com/CodexLink'>Test is just a test, it just redirects to my github.</a>", "html", "utf-8"
	)
	email_instance.attach(html_message)
	await astmp_instance.send_message(email_instance)

	astmp_instance.close() # Since we have a close(), we really need to construct a class because we can't just do the basic import as it may result in circular dependency.

	print(f"Message has been sent. (from: {os.environ.get('from')}, to: {os.environ.get('to')}")

@api_instance.on_event("shutdown") # We can use this for closing other tasks in CodexLink/folioblocks.
def shutdown():
	pass
	# for each_tasks in asyncio.all_tasks():
	# 	each_tasks.cancel()

	# print("All tasks cancelled.")


if __name__ == "__main__":
	try:
		uvicorn.run(
			app="__main__:api_instance",
			host="localhost",
			port=5001,
			reload=False
		)
	except RuntimeError:
		print("Event loop for the aiosmtplib is not handled or will say event loop is closed. We may need proper handling from the shutdown instance than using try-except here.")
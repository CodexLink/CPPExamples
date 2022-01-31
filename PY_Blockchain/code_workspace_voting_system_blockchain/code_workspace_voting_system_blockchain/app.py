import sys
import requests
import json
from flask import Flask, request, Response
from flask_cors import CORS
from blockchain import Blockchain

app = Flask(__name__)
CORS(app)

app_port = sys.argv[1]
current_node_url = "http://localhost:" + app_port
b = Blockchain(current_node_url)

@app.route('/blockchain')
def get_blockchain():
    return Response(b.get_blockchain(), status=200, content_type="application/json")
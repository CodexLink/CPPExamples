from fastapi import APIRouter, Depends, FastAPI, Header, HTTPException


async def verify_token(x_token: str = Header(...)):
    if x_token != "fake-super-secret-token":
        raise HTTPException(status_code=400, detail="X-Token header invalid")


async def verify_key(x_key: str = Header(...)):
    # if x_key != "fake-super-secret-key":
    #     raise HTTPException(status_code=400, detail="X-Key header invalid")
    app.state._state = {"data": "Hello World"}

app = FastAPI()

async def return_something():
    app.state._state = {"data": "Hello World"}


router = APIRouter(prefix="/wat", dependencies=[Depends(return_something)])

app.include_router(router)


@router.get("/items")
async def read_items():
    print(dir(app.state._state), app.state._state)
    return [{"item": "Foo"}, {"item": "Bar"}]


@router.get("/tests/")
async def yes():
    print(dir(app.state._state), app.state._state)
    return "yo"

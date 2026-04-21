from fastapi import FastAPI
from pydantic import BaseModel
import random

app = FastAPI()

class Request(BaseModel):
    price: float
    moving_avg: float

@app.post("/predict")
def predict(req: Request):
    # dummy model
    score = 0.8 if req.price > req.moving_avg else 0.3
    return {"score": score}

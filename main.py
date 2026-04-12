from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
from pydantic import BaseModel, Field
from typing import List, Optionalq
from datetime import datetime

app = FastAPI()

app.add_middleware(
    CORSMiddleware,
    allow_origins=["http://localhost:4200"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"]
)

class product(BaseModel):
    id: Optional[int] = None
    name: str = Field(min_length=1, max_length=100)
    price: float = Field(gt=0)
    stock: int = Field(ge=0)
    category: str = Field(min_length=1, max_length=100)
    description: Optional[str] = Field(None, max_length=500)
    created_at: Optional[datetime] = None

class productUpdate(BaseModel):
    name: Optional[str] = Field(None, min_length=1, max_length=100)
    price: Optional[float] = Field(None, gt=0)
    stock: Optional[int] = Field(None, ge=0)
    category: Optional[str] = Field(None, min_length=1, max_length=100)
    description: Optional[str] = Field(None, max_length=500)

database: List[product] = []
currentId = 1

def findProduct(id:int):
    for idx, product in enumerate(database):
        if product.id == id:
            return product, idx
    return None, None

@app.post("/products")
async def createProduct(product: product):
    global currentId
    product.id = currentId
    currentId += 1
    product.created_at = datetime.now()

    database.append(product)
    return product

@app.get("/products")
async def getAllProducts():
    return database

@app.get("/products/{name}")
async def getProduct(name: str):
    for product in database:
        if product.name.lower() == name.lower():
            return product

@app.delete("/products/{name}")
async def delete_product(name: str):
    for idx, product in enumerate(database):
        if product.name.lower() == name.lower():
            database.pop(idx)
            return None
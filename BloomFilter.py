import hashlib
import math

class BloomFilter:
  filter = []
  filterSize = None
  def __init__(self,size:int) -> None:
    self.createFilter(size)

  #FPRate -> acceptable false positivity rate
  #noOfKeys -> approx no. of keys 
  def __init__(self,FPRate:int, noOfKeys:int) -> None:
    size = self.getFilterSize(FPRate,noOfKeys)
    self.createFilter(size)

  def createFilter(self,size:int) -> None:
    self.filter = size*[False]
    self.filterSize = size

  def getFilterSize(self,FPRate:int, noOfKeys:int) -> int:
    size = -(noOfKeys * math.log(FPRate))/(math.log(2)**2)
    return abs(int(size))
    
  def insert(self,item:str) -> None:
    index = self.getIndex(item)
    self.filter[index] = True

  def getIndex(self,item:str) -> int:
    result = hashlib.sha256(item.encode())
    hash = int(result.hexdigest(),16)
    return hash % self.filterSize

  def check(self,item:str) -> bool:
    index = self.getIndex(item)
    return self.filter[index]


filter = BloomFilter(0.2,10)
print(filter.check("apple")) #False
filter.insert("apple")
print(filter.check("apple")) #True
print(filter.check("banana")) #False

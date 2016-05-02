#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

const int BARCODE_LENGTH = 12;
const int INIT_CAPACITY = 128;

enum ProductType
{
	FOOD,
	DRINK,
	SOAP,
	WAFFLE,
	WATER,
	COSMETIC,
	PAPER,
	FIZZY
};

struct Product
{
	ProductType type;
	char* name;
	char barcode[BARCODE_LENGTH];
  double price;
	size_t storeID;
};

struct Store
{
  char* name;
  Product* products;
  int productsCount;
  int capacity;
};

void MyStrCpy(char*& destination, const char* source)
{
	destination = new char[strlen(source) + 1];
	for (int i = 0; i <= strlen(source); i++)
	{
		destination[i] = source[i];
	}
}

void InitProduct(Product& p, ProductType type, char* name, char* barcode, double price, size_t storeID)
{
	p.type = type;
	MyStrCpy(p.name, name);
	strcpy(p.barcode, barcode);
	p.price = price;
	p.storeID = storeID;
}

void PrintProduct(const Product& p)
{
	cout << "Product name: " << p.name << endl;

	cout << "Product type: " << p.type << endl;
	cout << "Product barcode: " << p.barcode << endl;

	cout << "Product price: " << p.price << endl;
	cout << "StoreID: " << p.storeID << endl;
}

void InitStore(Store& store, const char* name)
{
  MyStrCpy(store.name, name);
  store.products = new Product[INIT_CAPACITY];
  store.productsCount = 0;
  store.capacity = INIT_CAPACITY;
}

void PrintStore(const Store& store)
{
  cout << "Store name: " << store.name << endl;
  cout << "Number of products: " << store.productsCount << endl;
  cout << "Store capacity: " << store.capacity << endl;

  for(int i = 0; i < store.productsCount; i++)
  {
    cout << "Product #" << i + 1 << endl;
    PrintProduct(store.products[i]);
    cout << endl;
  }
}

const char* FindCheapestStore(Store* stores, int storesCount, ProductType type)
{
  int storeIndex = -1;
  double cheapestPrice = stores[0].products[0].price;

  for(int i = 0; i < storesCount; i++)
  {
    for(int j = 0; j < stores[i].productsCount; j++)
    {
      if(stores[i].products[j].type == type)
      {
        if(stores[i].products[j].price < cheapestPrice)
        {
          cheapestPrice = stores[i].products[j].price;
          storeIndex = i;
        }
      }
    }
  }

  return stores[storeIndex].name;
}

bool AreEqual(const Store& store, ProductType type)
{
  Product temp;
  bool isFirst = true;
  for(int i = 0; i < store.productsCount; i++)
  {
    if(store.products[i].type == type)
    {
      if(isFirst)
      {
        InitProduct(temp, store.products[i].type, store.products[i].name, store.products[i].barcode, store.products[i].price, store.products[i].storeID);
        isFirst = false;
      }
      else
      {
        if(strcmp(temp.name, store.products[i].name) != 0 || temp.price != store.products[i].price)
          return false;
      }
    }
  }

  return true;
}

void ShiftProducts(Store& store, int index)
{
  for(int i = index; i < store.productsCount - 1; i++)
    store.products[i] = store.products[i + 1];
}

void RemoveProduct(Store& store, char* barcode)
{
  for(int i = 0; i < store.productsCount; i++)
  {
    if(strcmp(store.products[i].barcode, barcode) == 0)
    {
      ShiftProducts(store, i);
      store.productsCount--;
    }
  }
}

bool ProductExists(const Store& store, Product product)
{
  for(int i = 0; i < store.productsCount; i++)
  {
    if(strcmp(store.products[i].barcode, product.barcode) == 0)
      return true;
  }

  return false;
}

void AddProduct(Store& store, Product product)
{
  assert(("Store is full! Cannot add any more products.", store.productsCount < store.capacity));

  if(!ProductExists(store, product))
  {
    InitProduct(store.products[store.productsCount], product.type, product.name, product.barcode, product.price, product.storeID);
    store.productsCount++;
  }

}

int main()
{
	Product CocaCola, Morena, WaterMihalkovo, WaterBankya, WaterDevin;


	InitProduct(CocaCola, FIZZY, "Coca Cola", "789434832432", 1.2, 761234);
	InitProduct(Morena, WAFFLE, "Morena", "789876543432", 0.5, 721742);
	InitProduct(WaterMihalkovo, WATER, "Mihalkovo", "439434832432", 1.2, 723124);
	InitProduct(WaterBankya, WATER , "Bankya", "789434832432", 0.7, 761234);
	InitProduct(WaterDevin, WATER, "Morena", "119876543432", 0.8, 721742);


    PrintProduct(CocaCola);



	Store Billa, Kaufland, Lidl;

	InitStore(Billa, "Billa");
	AddProduct(Billa, CocaCola);
	AddProduct(Billa, Morena);
	AddProduct(Billa, WaterMihalkovo);

	InitStore(Kaufland, "Kaufland");
	AddProduct(Kaufland, WaterDevin);
	AddProduct(Kaufland, CocaCola);

	InitStore(Lidl, "Lidl");
	AddProduct(Lidl, WaterBankya);
	AddProduct(Lidl, CocaCola);



	Store arrMarkets[3];
	arrMarkets[0] = Kaufland;
	arrMarkets[1] = Billa;
	arrMarkets[2] = Lidl;

	cout << FindCheapestStore(arrMarkets, 3, WATER) << endl;



	delete[] WaterBankya.name;
	delete[] CocaCola.name;
	delete[] WaterDevin.name;
	delete[] WaterMihalkovo.name;
	delete[] Morena.name;
	delete[] Lidl.name;
	delete[] Kaufland.name;
	delete[] Billa.name;
	delete[] Lidl.products;
	delete[] Kaufland.products;
	delete[] Billa.products;
	
    return 0;
}

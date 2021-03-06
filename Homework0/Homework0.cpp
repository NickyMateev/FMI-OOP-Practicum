#include "iostream"
#include <string.h>
using namespace std;

const int MAX_DESTINATIONS = 3;
const int MAX_LENGTH = 1000;

struct City
{
	char* name;
	int population;
	bool hasMuseum;
};

struct Destination
{
	City city;
	int kilometers;
};

struct GPS
{
	City currentCity;
	Destination path[MAX_DESTINATIONS];
};

void MyStrCpy(char*& destination, char* source)
{
	destination = new char[strlen(source) + 1];
	for (int i = 0; i <= strlen(source); i++)
		destination[i] = source[i];
}

void InitCity(City& city, char* name, int population, bool hasMuseum)
{
	MyStrCpy(city.name, name);
	city.population = population;
	city.hasMuseum = hasMuseum;
}

void EnterCity(City& city)
{
	char name[MAX_LENGTH];
	int population;
	int hasMuseum;

	cout << "City name: ";
	cin >> name;
	cout << "City population: ";
	cin >> population;
	cout << "Has museum: " << endl << "No -> 0" << endl << "Yes -> 1" << endl;
	cout << "Your input: ";
	cin >> hasMuseum;

	while (hasMuseum != 0 && hasMuseum != 1)
	{
		cout << "Invalid integer! Try again..." << endl << "Your input: ";
		cin >> hasMuseum;
	}

	InitCity(city, name, population, hasMuseum);
}

void PrintCity(City city)
{
	cout << "City name: " << city.name << endl;
	cout << "City population(in thousands): " << city.population << endl;
	cout << "Has museum: ";
	if (city.hasMuseum)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

void InitDestination(Destination& d, City city, int kilometers)
{
	d.city = city;
	d.kilometers = kilometers;
}

void EnterDestination(Destination& d)
{
	City curCity;
	int kilometers;
	EnterCity(curCity);
	cout << "Kilometers: ";
	cin >> kilometers;
	InitDestination(d, curCity, kilometers);
}

void PrintDestination(Destination d)
{
	cout << "Destination info:" << endl;
	PrintCity(d.city);
	cout << "Kilometers: " << d.kilometers << endl;
}

void InitGPS(GPS& gps, City currentCity, Destination* path)
{
	gps.currentCity = currentCity;
	for (int i = 0; i < MAX_DESTINATIONS; i++)
		gps.path[i] = path[i];
}

void EnterGPS(GPS& gps)
{
	City gpsCity;
	Destination path[MAX_DESTINATIONS];

	cout << "GPS Info" << endl << "Current city info:" << endl;
	EnterCity(gpsCity);

	for (int i = 0; i < MAX_DESTINATIONS; i++)
	{
		cout << "Destination #" << i + 1 << endl;
		EnterDestination(path[i]);
	}

	InitGPS(gps, gpsCity, path);
}

void PrintGPS(GPS gps)
{
	cout << "GPS info:" << endl;
	cout << "Current city:" << endl;
	PrintCity(gps.currentCity);
  cout << endl;
	for (int i = 0; i < MAX_DESTINATIONS; i++)
	{
		cout << "Destination #" << i + 1 << endl;
		PrintDestination(gps.path[i]);
		cout << endl;
	}
}

void PrintDestinationsWithMuseums(GPS gps)
{
	for (int i = 0; i < MAX_DESTINATIONS; i++)
	{
		if (gps.path[i].city.hasMuseum)
			cout << "City name: " << gps.path[i].city.name << endl;
	}
}

Destination ClosestDestination(GPS gps)
{
	int index = 0;

	for (int i = 1; i < MAX_DESTINATIONS; i++)
	{
		if (gps.path[i].kilometers < gps.path[index].kilometers)
			index = i;
	}
	return gps.path[index];
}

Destination FarthestDestination(GPS gps)
{
	int index = 0;

	for (int i = 1; i < MAX_DESTINATIONS; i++)
	{
		if (gps.path[i].kilometers > gps.path[index].kilometers)
			index = i;
	}
	return gps.path[index];
}

void SortDestinationsByName(GPS gps)
{
	for (int i = 0; i < MAX_DESTINATIONS - 1; i++)
	{
		for (int j = 0; j < MAX_DESTINATIONS - i - 1; j++)
		{
			if (strcmp(gps.path[j].city.name, gps.path[j + 1].city.name) > 0)
			{
				Destination tempDest = gps.path[j];
				gps.path[j] = gps.path[j + 1];
				gps.path[j + 1] = tempDest;
			}
		}
	}
}

int main()
{
	City varna, sofia;
	InitCity(varna, "Varna", 500, 0);
	InitCity(sofia, "Sofia", 2000, 1);

	GPS gps;
	EnterGPS(gps);

	cout << "Destinations with museums:" << endl;
	PrintDestinationsWithMuseums(gps);
	cout << endl;

	Destination closestDest = ClosestDestination(gps);
	cout << "Closest city: " << closestDest.city.name << endl;
	cout << "Kilometers: " << closestDest.kilometers << endl;
	cout << endl;

	Destination farthestDest = FarthestDestination(gps);
	cout << "Farthest city: " << farthestDest.city.name << endl;
	cout << "Kilometers: " << farthestDest.kilometers << endl;
	cout << endl;

	SortDestinationsByName(gps);
	PrintGPS(gps);

  // deleting dynamically allocated memory:
  delete[] varna.name;
  delete[] sofia.name;

  delete[] gps.currentCity.name;
  for(int i = 0; i < MAX_DESTINATIONS; i++)
    gps.path[i].city.name;

  return 0;
}

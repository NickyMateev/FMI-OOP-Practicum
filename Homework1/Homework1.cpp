#include "iostream"
#include "time.h"
using namespace std;

const int DEFAULT_SONG_NAME_LENGTH = 50;
const int DEFAULT_ARTIST_NAME_LENGTH = 50;
const int INIT_ALBUM_CAPACITY = 50;

const int DEFAULT_NUMBER_OF_SONGS = 1000;
const int DEFAULT_NUMBER_OF_ALBUMS = 100;
const int DEFAULT_BATTERY_POWER = 100;

class Song
{
public:
	Song();
	Song(char* name, float length);
	Song(char* name, float length, char* artist);
	~Song();
	const char* getName() const;
	void setName(const char* name);
	float getLength() const;
	void setLength(const float length);
	const char* getArtist() const;
	void setArtist(const char* artist);
private:
	char* name;		//song name
	float length;	//song length
	char* artist;	//artist/group name
};

class Album
{
public:
	Album();
	Album(char* name);
	Album(char* name, Song song);
	Album(char* name, Song* songs, size_t numberOfSongs);
	Album(char* name, char* artist, Song* songs, size_t numberOfSongs);
	~Album();
	void AddSong(const Song& newSong);	// check if the song's artist is the same for all songs in the album
	void RemoveSong(const char* name);	// remove song by name
	void RemoveSong(const int index);	// remove song by index

	const char* getName() const;
	void setName(const char* name);
	const char* getArtist() const;
	void setArtist(const char* artist);
	size_t getNumberOfSongs() const;
	void setNumberOfSongs(const size_t numberOfSongs);
	size_t getAlbumCapacity() const;
	void setAlbumCapacity(const size_t albumCapacity);
	const Song* getSongs() const;
	void setSongs(const Song* songs, const size_t numberOfSongs);
private:
	char* name;		// album name
	char* artist;	// album's artist name

	Song* songs;	// songs in the album
	size_t numberOfSongs; // number of songs currently on the album
	size_t albumCapacity; // album capacity
};

class MP3Player
{
public:
	MP3Player();
	MP3Player(Song* songs, size_t numberOfSongs);
	MP3Player(Album* albums, size_t numberOfAlbums);
	MP3Player(Song* songs, Album* albums, size_t numberOfSongs, size_t numberOfAlbums);
	~MP3Player();

	void AddSong(const Song& song);
	void AddSongs(const Song*& songs, const size_t numberOfSongs);
	void AddAlbum(const Album& album);
	void AddAlbums(const Album*& albums, const size_t numberOfAlbums);
	void RemoveAlbum(const char* name);

	void Charge();
	void StopCharge();
	void Play(bool shuffle);
private:
	Song* songs;
	Album* albums;
	int batteryPower;
	bool isCharge;
	size_t currentSong;

	size_t numberOfSongs, numberOfAlbums;
	size_t songsCapacity, albumsCapacity;

	void addAllSongsFromAlbumToMP3(const Album& album);
	int myRandomSong();
};

void mystrcpy(char*& destination, const char* source)
{
	destination = new char[strlen(source) + 1];
	for (size_t i = 0; i <= strlen(source); i++)
		destination[i] = source[i];
}

void copySongs(Song& destination, const Song& source)
{
	destination.setName(source.getName());
	destination.setLength(source.getLength());
	destination.setArtist(source.getArtist());
}

void copyAlbums(Album& destination, const Album& source)
{
	destination.setName(source.getName());
	destination.setArtist(source.getArtist());
	destination.setNumberOfSongs(source.getNumberOfSongs());
	destination.setAlbumCapacity(source.getAlbumCapacity());
	destination.setSongs(source.getSongs(), source.getNumberOfSongs());
}

int MP3Player::myRandomSong()
{
	srand(time(NULL));
	return rand() % numberOfSongs;
}

void MP3Player::addAllSongsFromAlbumToMP3(const Album& album)
{
	int currentAlbumNumOfSongs = album.getNumberOfSongs();
	for (size_t i = 0; i < currentAlbumNumOfSongs; i++)	// copying each song from the album to the songs array of the MP3 player
	{
		if (this->numberOfSongs >= songsCapacity)
		{
			cout << "Not all songs were saved from the album \""<< album.getName() <<"\"! There's no space for anymore songs on the MP3 player." << endl;
			return;
		}

		copySongs(this->songs[this->numberOfSongs], album.getSongs()[i]);
		this->numberOfSongs++;
	}
}

//Song implementations:
Song::Song()
{
	mystrcpy(name, "UnknownSongName");
	mystrcpy(artist, "UnknownArtistName");
	length = 0;
}

Song::Song(char* name, float length)
{
	mystrcpy(this->name, name);
	mystrcpy(artist, "UnknownArtist");
	this->length = length;
}

Song::Song(char* name, float length, char* artist)
{
	mystrcpy(this->name, name);
	mystrcpy(this->artist, artist);
	this->length = length;
}

Song::~Song()
{
	delete[] name;
	delete[] artist;
}

const char* Song::getName() const
{
	return name;
}

void Song::setName(const char* name)
{
	delete[] this->name;
	mystrcpy(this->name, name);
}

float Song::getLength() const
{
	return length;
}

void Song::setLength(const float length)
{
	this->length = length;
}

const char* Song::getArtist() const
{
	return artist;
}

void Song::setArtist(const char* artist)
{
	delete[] this->artist;
	mystrcpy(this->artist, artist);
}

//Album implementations
Album::Album()
{
	//Album("UnknownAlbumName");
	mystrcpy(this->name, "UnknownAlbumName");
	mystrcpy(artist, "UnknownArtistName");

	albumCapacity = INIT_ALBUM_CAPACITY;
	songs = new Song[albumCapacity];
	numberOfSongs = 0;
}

Album::Album(char* name)
{
	mystrcpy(this->name, name);
	mystrcpy(artist, "UnknownArtist");

	albumCapacity = INIT_ALBUM_CAPACITY;
	songs = new Song[albumCapacity];
	numberOfSongs = 0;
}

Album::Album(char* name, Song song)
{
	mystrcpy(this->name, name);
	mystrcpy(artist, "UnknownArtist");

	albumCapacity = INIT_ALBUM_CAPACITY;
	songs = new Song[albumCapacity];
	copySongs(songs[0], song);

	numberOfSongs = 1;
}

Album::Album(char* name, Song* songs, size_t numberOfSongs)
{
	mystrcpy(this->name, name);
	mystrcpy(artist, "UnknownArtist");

	albumCapacity = 2 * numberOfSongs;
	songs = new Song[albumCapacity];
	this->numberOfSongs = numberOfSongs;

	for (size_t i = 0; i < this->numberOfSongs; i++)
		copySongs(this->songs[i], songs[i]);

}

Album::Album(char* name, char* artist, Song* songs, size_t numberOfSongs)
{
	mystrcpy(this->name, name);
	mystrcpy(this->artist, artist);

	albumCapacity = 2 * numberOfSongs;
	this->songs = new Song[albumCapacity];
	this->numberOfSongs = numberOfSongs;

	for (size_t i = 0; i < this->numberOfSongs; i++)
		copySongs(this->songs[i], songs[i]);
}

Album::~Album()
{
	delete[] name;
	delete[] artist;
	delete[] songs;
}

const char* Album::getName() const
{
	return name;
}

void Album::setName(const char* name)
{
	delete[] this->name;
	mystrcpy(this->name, name);
}

const char* Album::getArtist() const
{
	return artist;
}

void Album::setArtist(const char* artist)
{
	delete[] this->artist;
	mystrcpy(this->artist, artist);
}

size_t Album::getNumberOfSongs() const
{
	return numberOfSongs;
}

void Album::setNumberOfSongs(const size_t numberOfSongs)
{
	this->numberOfSongs = numberOfSongs;
}

size_t Album::getAlbumCapacity() const
{
	return albumCapacity;
}

void Album::setAlbumCapacity(const size_t albumCapacity)
{
	this->albumCapacity = albumCapacity;
}

const Song* Album::getSongs() const
{
	return songs;
}

void Album::setSongs(const Song* songs, const size_t numberOfSongs)
{
	if (numberOfSongs > albumCapacity)
	{
		cout << "Unable to set new songs! The capacity of the album is smaller than the new number of songs!" << endl;
		return;
	}

	this->numberOfSongs = numberOfSongs;
	for (size_t i = 0; i < this->numberOfSongs; i++)
		copySongs(this->songs[i], songs[i]);
}

void Album::AddSong(const Song& newSong)
{
	if (numberOfSongs == albumCapacity)
	{
		cout << "The album is full! Cannot add more songs to it." << endl;
		return;
	}

	if (newSong.getArtist() != artist)
	{
		cout << "This song has a different artist than the album you're trying to put it in! Cannot add this song to the the album." << endl;
		return;
	}

	copySongs(songs[numberOfSongs], newSong);
	numberOfSongs++;
	cout << "\"" << newSong.getName() << "\" successfully added to the album!" << endl;
}

void Album::RemoveSong(const char* name)
{
	for (size_t i = 0; i < numberOfSongs; i++)
	{
		if (strcmp(songs[i].getName(), name) == 0)
		{
			for (size_t j = i; j < numberOfSongs - 1; j++)
				copySongs(songs[j], songs[j + 1]);

			numberOfSongs--;
			return;
		}
	}

	cout << "Song does not exist in the album!" << endl;
}

void Album::RemoveSong(const int index)
{
	if (index >= numberOfSongs)
	{
		cout << "Invalid index! There aren't that many songs in the album." << endl;
		return;
	}

	for (size_t i = index; i < numberOfSongs - 1; i++)
		copySongs(songs[i], songs[i + 1]);

	numberOfSongs--;
}

MP3Player::MP3Player()
{
	songsCapacity = DEFAULT_NUMBER_OF_SONGS;
	albumsCapacity = DEFAULT_NUMBER_OF_ALBUMS;
	numberOfSongs = 0;
	numberOfAlbums = 0;

	songs = new Song[songsCapacity];
	albums = new Album[albumsCapacity];
	batteryPower = DEFAULT_BATTERY_POWER;
	isCharge = false;
	currentSong = 0;
}

MP3Player::MP3Player(Song* songs, size_t numberOfSongs)
{
	songsCapacity = DEFAULT_NUMBER_OF_SONGS;
	albumsCapacity = DEFAULT_NUMBER_OF_ALBUMS;
	this->numberOfSongs = numberOfSongs;
	numberOfAlbums = 0;

	batteryPower = DEFAULT_BATTERY_POWER;
	isCharge = false;
	currentSong = 0;

	this->songs = new Song[songsCapacity];
	for (size_t i = 0; i < this->numberOfSongs; i++)
		copySongs(this->songs[i], songs[i]);

	albums = new Album[albumsCapacity];
}

MP3Player::MP3Player(Album* albums, size_t numberOfAlbums)
{
	songsCapacity = DEFAULT_NUMBER_OF_SONGS;
	albumsCapacity = DEFAULT_NUMBER_OF_ALBUMS;
	numberOfSongs = 0;
	this->numberOfAlbums = numberOfAlbums;

	batteryPower = 100;
	isCharge = false;
	currentSong = 0;

	songs = new Song[songsCapacity];
	this->albums = new Album[albumsCapacity];

	for (size_t i = 0; i < this->numberOfAlbums; i++)
	{
		copyAlbums(this->albums[i], albums[i]);	// copying the albums
		addAllSongsFromAlbumToMP3(albums[i]);	// copying all songs from the album to the songs array
	}
}

MP3Player::MP3Player(Song* songs, Album* albums, size_t numberOfSongs, size_t numberOfAlbums)
{
	songsCapacity = DEFAULT_NUMBER_OF_SONGS;
	albumsCapacity = DEFAULT_NUMBER_OF_ALBUMS;
	this->numberOfSongs = numberOfSongs;
	this->numberOfAlbums = numberOfAlbums;

	batteryPower = DEFAULT_BATTERY_POWER;
	isCharge = false;
	currentSong = 0;

	this->songs = new Song[DEFAULT_NUMBER_OF_SONGS];
	this->albums = new Album[DEFAULT_NUMBER_OF_ALBUMS];

	for (size_t i = 0; i < this->numberOfSongs; i++)
		copySongs(this->songs[i], songs[i]);

	for (size_t i = 0; i < this->numberOfAlbums; i++)
	{
		copyAlbums(this->albums[i], albums[i]);	// copying the albums
		addAllSongsFromAlbumToMP3(albums[i]);   // copying all songs from the album to the songs array
	}
}

MP3Player::~MP3Player()
{
	delete[] songs;
	delete[] albums;
}

void MP3Player::AddSong(const Song& song)
{
	if (numberOfSongs >= songsCapacity)
	{
		cout << "The MP3Player is full! The song cannot be added. The maximum capacity for songs was reached." << endl;
		return;
	}

	copySongs(songs[numberOfSongs], song);
	numberOfSongs++;
}

void MP3Player::AddSongs(const Song*& songs, const size_t numberOfSongs)
{
	if (numberOfSongs >= songsCapacity)
	{
		cout << "The MP3Player is full! The songs cannot be saved. The maximum capacity for songs was reached." << endl;
		return;
	}

	for (size_t i = 0; i < numberOfSongs; i++)
	{
		if (numberOfSongs >= songsCapacity)
		{
			cout << "The MP3Player is full! Not all songs were saved. The maximum capacity for songs was reached." << endl;
			return;
		}

		copySongs(this->songs[this->numberOfSongs], songs[i]);
		this->numberOfSongs++;
	}
}

void MP3Player::AddAlbum(const Album& album)
{
	if (numberOfAlbums >= albumsCapacity)
	{
		cout << "The MP3Player is full! The album cannot be added. The maximum capacity for albums was reached." << endl;
		return;
	}

	copyAlbums(albums[numberOfAlbums], album);
	addAllSongsFromAlbumToMP3(album);

	numberOfAlbums++;
}

void MP3Player::AddAlbums(const Album*& albums, const size_t numberOfAlbums)
{
	if (this->numberOfAlbums >= albumsCapacity)
	{
		cout << "The MP3Player is full! The albums cannot be saved. The maximum capacity for albums was reached." << endl;
		return;
	}

	for (size_t i = 0; i < numberOfAlbums; i++)
	{
		if (numberOfAlbums >= albumsCapacity)
		{
			cout << "The MP3Player is full! Not all albums were be saved. The maximum capacity for albums was reached." << endl;
			return;
		}

		copyAlbums(this->albums[this->numberOfAlbums], albums[i]);
		this->numberOfAlbums++;
		addAllSongsFromAlbumToMP3(albums[i]);
	}
}

void MP3Player::RemoveAlbum(const char* name)
{
	for (size_t i = 0; i < numberOfAlbums; i++)
	{
		if (strcmp(albums[i].getName(), name) == 0)
		{
			// removing the songs in the album from the array of songs
			int albumNumOfSongs = albums[i].getNumberOfSongs();
			for (size_t j = 0; j < albumNumOfSongs; j++)	// loop for all the songs in the album that we'll remove
			{
				for (size_t k = 0; k < this->numberOfSongs; k++)	// loop for all the songs in the MP3Player
				{
					if (strcmp(albums[i].getSongs()[j].getName(), songs[k].getName()) == 0)	// if we encounter one of the album's songs in the songs array -> we remove it
					{
						for (size_t q = k; q < this->numberOfSongs - 1; q++)
							copySongs(songs[q], songs[q + 1]);
						numberOfSongs--;
					}
				}
			}

			// removing the album itself
			for (size_t j = i;  j < numberOfAlbums - 1;  j++)
				copyAlbums(albums[j], albums[j + 1]);

			numberOfAlbums--;
			return;
		}
	}
	cout << "Album was not found on the MP3Player!" << endl;
}

void MP3Player::Charge()
{
	isCharge = true;
}

void MP3Player::StopCharge()
{
	isCharge = false;
}

void MP3Player::Play(bool shuffle)
{
	if (batteryPower <= 15)
		cout << "The battery is low(currently at " << batteryPower << "%)!" << endl;

	if (isCharge)
	{
		cout << "The MP3Player is currently charging. Cannot play music while charging..." << endl;
		return;
	}

	if (numberOfSongs == 0)
	{
		cout << "No songs in the MP3Player..." << endl;
		return;
	}

	if (shuffle)
		currentSong = myRandomSong();
	else
	{
		if (currentSong >= numberOfSongs)
			currentSong = 0;
	}

	cout << "Currently playing: \"" << songs[currentSong].getName() << "\"" << endl;
	batteryPower -= (int)songs[currentSong].getLength();

	if (batteryPower < 0)
	{
		batteryPower = 0;
		cout << "The song was interrupted, because the MP3Player's battery died. Please charge the MP3Player..." << endl;
	}
	else
	{
		cout << "The song finished." << endl;
		currentSong++;
	}
}

int main()
{
	// Songs for the eminem album
	Song* songsAlbum1 = new Song[4];
	copySongs(songsAlbum1[0], Song("Rap God", 3.14, "Eminem"));
	copySongs(songsAlbum1[1], Song("Till I Collapse", 3.5, "Eminem"));
	copySongs(songsAlbum1[2], Song("The Real Slim Shady", 3, "Eminem"));
	copySongs(songsAlbum1[3], Song("I need a Doctor", 5.2, "Eminem"));

	Album eminemAlbum("Eminem Album", "Eminem", songsAlbum1, 4);

	// Songs for the eazy album
	Song* songsAlbum2 = new Song[2];
	copySongs(songsAlbum2[0], Song("Boys N' Tha Hood", 6.04, "Eazy E"));
	copySongs(songsAlbum2[1], Song("Real Thugs", 3.14, "Eazy E"));

	Album eazyAlbum("Eazy E Album", "Eazy E", songsAlbum2, 2);

	// Making an array of albums
	Album* albums = new Album[2];
	copyAlbums(albums[0], eminemAlbum);
	copyAlbums(albums[1], eazyAlbum);

	// Making an array of random songs
	Song* randomSongs = new Song[3];
	copySongs(randomSongs[0], Song("Moonlight Sonata", 6.4, "Beethoven"));
	copySongs(randomSongs[1], Song("Check Yo Self", 4.33, "Ice Cube"));
	copySongs(randomSongs[2], Song("Wrecking ball", 3.8, "Miley Cyrus"));

	// -----------------------------------------

	MP3Player mp3(randomSongs, albums, 3, 2);

	char* str;
	mystrcpy(str, "Eazy E Album");
	mp3.RemoveAlbum(str);

	mp3.AddSong(Song("Blue Magic", 4.14, "Jay-Z"));

	//mp3.Charge();
	for (size_t i = 0; i < 25; i++)
		mp3.Play(false);

	delete[] songsAlbum1;
	delete[] songsAlbum2;
	delete[] albums;
	delete[] str;
	return 0;
}

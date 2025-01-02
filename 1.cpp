#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Photo
{
	std::string id;
	std::string data;
	std::string metadata;
};

class Server
{
public:
	std::unordered_map<std::string, Photo> shard;
	void storePhoto(const Photo &photo)
	{
		shard[photo.id] = photo;
	}
	Photo getPhoto(const std::string &photoId)
	{
		return shard[photoId];
	}
};

class Haystack
{
public:
	std::vector<Server> servers;
	void storePhoto(const Photo &photo)
	{
		std::string contentAddress = std::to_string(std::hash<std::string>{}(photo.data));
		int serverIndex = std::hash<std::string>{}(contentAddress) % servers.size();
		servers[serverIndex].storePhoto(photo);
	}
	Photo getPhoto(const std::string &photoId)
	{
		int serverIndex = std::hash<std::string>{}(photoId) % servers.size();
		return servers[serverIndex].getPhoto(photoId);
	}
};
int main()
{
	Haystack haystack;
	haystack.servers.resize(3);
	Photo photo1 = {"1", "BinaryData1", "Metadata1"};
	Photo photo2 = {"2", "BinaryData2", "Metadata2"};
	haystack.storePhoto(photo1);
	haystack.storePhoto(photo2);
	Photo retrievedPhoto1 = haystack.getPhoto("1");
	Photo retrievedPhoto2 = haystack.getPhoto("2");
	cout << "Retrieved Photo 1: " << retrievedPhoto1.metadata << endl;
	cout << "Retrieved Photo 2: " << retrievedPhoto2.metadata << endl;
	return 0;
}
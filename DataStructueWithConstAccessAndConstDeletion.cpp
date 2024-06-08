#include <iostream>
#include <vector>
#include <unordered_map>
#include "bits/stdc++.h"

using namespace std;

#define ll long long int
class ConstantTimeDS 
{
public:
    void add(ll num)
	{
        if (index_map.find(num) == index_map.end()) {
            data.push_back(num);
            index_map[num] = data.size() - 1;
        }
    }

    bool remove(ll index) {
        if (index >= 0 && index < data.size()) {
            ll num_to_remove = data[index];
            ll last_element = data.back();

            // Swap the element to be removed with the last element
            data[index] = last_element;
            data.pop_back();

            // Update the index of the last element in the map
            index_map[last_element] = index;
            // Erase the entry for the removed element from the map
            index_map.erase(num_to_remove);

            return true;
        }

        return false;
    }

    ll get(ll index) {
        if (index >= 0 && index < data.size())
            return data[index];
        
        // Return some default value to indicate invalid index or handle as per your requirements
        return -1;
    }

private:
    std::vector<ll> data;
    std::unordered_map<ll, ll> index_map;
};

int main()
{
    ConstantTimeDS ds;
	for(ll i=0;i<10;i++)
	{
		ds.add(3*i + 8);
	}
	cout<<"Array: ";
	for(ll i=0;i<10;i++)
	{
		cout<<ds.get(i);
	}
	for(int i=0;i<2;i++)
	{
		ds.remove(0);
	}
	cout<<"\nNew Array: ";
	for(ll i=0;i<10;i++)
	{
		cout<<ds.get(i);
	}
	
    return 0;
}


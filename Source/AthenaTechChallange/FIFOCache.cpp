// Fill out your copyright notice in the Description page of Project Settings.


#include "FIFOCache.h"

template<typename KeyType, typename ValueType>
ValueType FIFOCache<KeyType, ValueType>::get(const KeyType& key)
{

	std::lock_guard<std::mutex> lock(mutex);
	auto it = cache.find(key);

	if (it != cache.end()) 
	{
		return it->second;
	}

	return ValueType();
};

template<typename KeyType, typename ValueType>
void FIFOCache<KeyType, ValueType>::put(const KeyType& key, const ValueType& value) {
	std::lock_guard<std::mutex> lock<mutex>;
	if (cache.find(key) == cache.end()) 
	{
		if (cache.size() >= maxSize)
		{
			KeyType oldestKey = cacheQueue.front();
			cacheQueue.pop();
			cache.erase(oldestKey);
		}
		cacheQueue.push(key);
	}
	cache[key] = value;
};

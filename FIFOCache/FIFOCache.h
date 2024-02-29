// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <unordered_map>
#include <queue>
#include <mutex>
/**
 * 
 */
template<typename KeyType, typename ValueType>
class ATHENATECHCHALLANGE_API FIFOCache
{
	GENERATED_BODY()

private:
	size_t maxSize;
	std::unordered_map<KeyType, ValueType> cache;
	std::queue<KeyType> cacheQueue;
	std::mutex mutex;

public:
	FIFOCache(size_t maxSize) : maxSize(maxSize) {};
	std::invoke_result_t<ValueType> get(const KeyType& key);
	void put(const KeyType& key, const ValueType& value);
	~FIFOCache();
};


#include "ProjectBlueprintFunctionLibrary.h"

FActorTransform UProjectBlueprintFunctionLibrary::GenerateRandomLocationAndRotation(const TArray<int32>& minBoundary, const TArray<int32>& maxBoundary,
																					const TArray<float>& minRotation, const TArray<float>& maxRotation) 
{
	// Generate random x, y, z variables from min and max boundary
	int32 newX = FMath::RandRange(minBoundary[0], maxBoundary[0]);
	int32 newY = FMath::RandRange(minBoundary[1], maxBoundary[1]);
	int32 newZ = FMath::RandRange(minBoundary[2], maxBoundary[2]);

	// Generate random roll, pitch, yaw variables from min and max rotation
	float newRoll = FMath::RandRange(minRotation[0], maxRotation[0]);
	float newPitch = FMath::RandRange(minRotation[1], maxRotation[1]);
	float newYaw = FMath::RandRange(minRotation[2], maxRotation[2]);

	FVector newLocation = FVector(newX, newY, newZ);
	FRotator newRotation = FRotator(newPitch, newYaw, newRoll);

	UE_LOG(LogTemp, Warning, TEXT("Generated new location: %s"), *newLocation.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Generated new rotation: %s"), *newRotation.ToString());

	return FActorTransform(newLocation, newRotation);
}

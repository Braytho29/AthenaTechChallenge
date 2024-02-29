#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ProjectBlueprintFunctionLibrary.generated.h"

USTRUCT(BlueprintType)
struct FActorTransform 
{

	GENERATED_BODY()

	// Location vector (x,y,z)
	UPROPERTY(BlueprintReadOnly)
	FVector Location;

	// Rotation vector (pitch, yaw, roll)
	UPROPERTY(BlueprintReadOnly)
	FRotator Rotation;

	// Constructor with default values
	FActorTransform() : Location(FVector(0, 0, 0)), Rotation(FRotator(0, 0, 0)) {};

	// Constructor
	FActorTransform(FVector NewLocation, FRotator NewRotation) : Location(NewLocation), Rotation(NewRotation) {};
};


/**
 *
 */
UCLASS()
class ATHENATECHCHALLANGE_API UProjectBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,
		meta = (ToolTip = "Generates a random location and rotation in bounding area."), Category = "BlueprintLibrary")
	/**
	 *	Returns a random location and rotation from a given set of boundaries.
	 *
	 *	@param minBoundary An array of coordinates (x, y, z)
	 *  @param maxBoundary An array of coordinates (x, y, z)
	 *  @param minRotation An array of rotations (roll, pitch, yaw)
	 *  @param maxRotation An array of rotations (roll, pitch, yaw)
	*/
	static FActorTransform GenerateRandomLocationAndRotation(const TArray<int32>& minBoundary, const TArray<int32>& maxBoundary,
															  const TArray<float>& minRotation, const TArray<float>& maxRotation);
};

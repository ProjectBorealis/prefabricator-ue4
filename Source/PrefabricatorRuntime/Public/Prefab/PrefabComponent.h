//$ Copyright 2015-24, Code Respawn Technologies Pvt Ltd - All Rights Reserved $//

#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#if WITH_EDITORONLY_DATA
#include "Engine/Texture2D.h"
#endif

#include "PrefabComponent.generated.h"

class UPrefabricatorAsset;
class UPrefabricatorAssetInterface;

UCLASS(Blueprintable)
class PREFABRICATORRUNTIME_API UPrefabComponent : public USceneComponent {
	GENERATED_UCLASS_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Prefabricator", Meta=(DisplayName="Prefab"))
	TSoftObjectPtr<UPrefabricatorAssetInterface> PrefabAssetInterface;

	virtual void OnRegister() override;
	virtual FBoxSphereBounds CalcBounds(const FTransform& LocalToWorld) const;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& e) override;
#endif // WITH_EDITOR
	
private:
#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UTexture2D> EditorSpriteTexture;
#endif // WITH_EDITORONLY_DATA
};


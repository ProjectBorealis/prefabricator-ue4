//$ Copyright 2015-24, Code Respawn Technologies Pvt Ltd - All Rights Reserved $//

#include "ConstructionSystem/Tools/ConstructionSystemTool.h"

#include "ConstructionSystemComponent.h"

#include "GameFramework/PlayerController.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(ConstructionSystemTool)

void UConstructionSystemTool::InitializeTool(UConstructionSystemComponent* ConstructionComponent)
{
}

void UConstructionSystemTool::DestroyTool(UConstructionSystemComponent* ConstructionComponent)
{
	APlayerController* PC = Cast<APlayerController>(ConstructionComponent ? ConstructionComponent->GetOwner() : nullptr);
	if (PC && PC->InputComponent) {
		UnregisterInputCallbacks(PC->InputComponent);
	}
}

void UConstructionSystemTool::OnToolEnable(UConstructionSystemComponent* ConstructionComponent)
{
	bToolEnabled = true;
}

void UConstructionSystemTool::OnToolDisable(UConstructionSystemComponent* ConstructionComponent)
{
	bToolEnabled = false;
}


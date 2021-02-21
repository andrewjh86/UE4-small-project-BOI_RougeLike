// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BindingOfIssac3d : ModuleRules
{
	public BindingOfIssac3d(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}

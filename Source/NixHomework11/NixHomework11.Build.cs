// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NixHomework11 : ModuleRules
{
	public NixHomework11(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
            "AIModule"
        });

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"NixHomework11",
			"NixHomework11/Variant_Platforming",
			"NixHomework11/Variant_Platforming/Animation",
			"NixHomework11/Variant_Combat",
			"NixHomework11/Variant_Combat/AI",
			"NixHomework11/Variant_Combat/Animation",
			"NixHomework11/Variant_Combat/Gameplay",
			"NixHomework11/Variant_Combat/Interfaces",
			"NixHomework11/Variant_Combat/UI",
			"NixHomework11/Variant_SideScrolling",
			"NixHomework11/Variant_SideScrolling/AI",
			"NixHomework11/Variant_SideScrolling/Gameplay",
			"NixHomework11/Variant_SideScrolling/Interfaces",
			"NixHomework11/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}

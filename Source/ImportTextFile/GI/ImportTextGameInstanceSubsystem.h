// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ImportTextGameInstanceSubsystem.generated.h"

/**
 * テキストファイルからテキストを読み込むテスト用
 */
UCLASS()
class IMPORTTEXTFILE_API UImportTextGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:

	//環境変数を取得
	UFUNCTION(BlueprintCallable) FString ReadEnvironmentVariable();

	//.txtファイルから文字列を読み込む
	UFUNCTION(BlueprintCallable) FString ReadTextFile();

	//JSonファイルから文字列を読み込む
	UFUNCTION(BlueprintCallable) FString ReadJsonFile(FString Key);
};

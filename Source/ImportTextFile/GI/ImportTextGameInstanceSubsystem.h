// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ImportTextGameInstanceSubsystem.generated.h"

/**
 * �e�L�X�g�t�@�C������e�L�X�g��ǂݍ��ރe�X�g�p
 */
UCLASS()
class IMPORTTEXTFILE_API UImportTextGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:

	//���ϐ����擾
	UFUNCTION(BlueprintCallable) FString ReadEnvironmentVariable();

	//.txt�t�@�C�����當�����ǂݍ���
	UFUNCTION(BlueprintCallable) FString ReadTextFile();

	//JSon�t�@�C�����當�����ǂݍ���
	UFUNCTION(BlueprintCallable) FString ReadJsonFile(FString Key);
};

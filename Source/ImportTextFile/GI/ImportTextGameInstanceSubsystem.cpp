// Fill out your copyright notice in the Description page of Project Settings.


#include <string>
#include <stdlib.h>
#include "Misc/FileHelper.h"
#include "JsonUtilities/Public/JsonUtilities.h"
#include "Runtime/Json/Public/Serialization/JsonReader.h"
#include "ImportTextGameInstanceSubsystem.h"

FString UImportTextGameInstanceSubsystem::ReadEnvironmentVariable()
{
    FString EnString;

    //変数の値を格納するバッファー
    wchar_t* pValue;
    //buffer のサイズ
    size_t len;
    //環境変数から取得した文字列
    std::wstring OutValue;

    //環境変数から変数を読み込み
    errno_t ErrorCode = _wdupenv_s(&pValue, &len, L"TESTUE4CONFIG");

    if (pValue)
    {
        //wstringに格納
        OutValue = pValue;
        //バッファを開放
        free(pValue);

        //FStringに変換
        EnString = FString(OutValue.c_str());
    }

    return EnString;
}

UFUNCTION(BlueprintCallable)FString UImportTextGameInstanceSubsystem::ReadTextFile()
{
    FString Output;
    if (GEngine)
    {
        //環境変数からConfigファイル下のテキストファイルの場所を取得
        FString FilePath = ReadEnvironmentVariable() + "TextConfig.txt";

        //ファイルが存在しなければ読み込み中止
        if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath))
        {
            return Output;
        }

        //ファイルサイズ取得
        const int64 FileSize = FPlatformFileManager::Get().GetPlatformFile().FileSize(*FilePath);
        //ファイル読み込み
        FFileHelper::LoadFileToString(Output, *FilePath);    
    }

    return Output;
}

UFUNCTION(BlueprintCallable)FString UImportTextGameInstanceSubsystem::ReadJsonFile(FString Key)
{
    FString Output;

    FString RawData;

    //環境変数からConfigファイル下のテキストファイルの場所を取得
    FString FilePath = ReadEnvironmentVariable() + "TextConfig.json";

    //ファイルを読み取る
    if (FFileHelper::LoadFileToString(RawData, *FilePath))
    {
        // FJsonObject(Jsonデータの入れ物)を作成
        TSharedPtr<FJsonObject> JsonRootObject = MakeShareable(new FJsonObject);

        //FStringからJsonを読み込むためのReaderを作成
        TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(RawData);

        // Json文字列からJsonオブジェクトに読み込み
        if (FJsonSerializer::Deserialize(JsonReader, JsonRootObject))
        {
            //Keyの値を取得
            Output = JsonRootObject->GetStringField(Key);
        }
    }

    return Output;
}

// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bull Cows!"));
    PrintLine(TEXT("Press enter to continue..."));
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();
    PrintLine(TEXT("Guess the 6 letter word"));
    if (Input == HiddenWord)
    {
        PrintLine(TEXT("You Win!"));
    }
    else
    {
        PrintLine(TEXT("You Lose!"));
    }
}
// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    // Welcome player
    PrintLine(TEXT("Welcome to Bull Cows!"));
    PrintLine(TEXT("Press enter to continue..."));

    SetupGame();
    PrintLine(TEXT("Guess the 6 letter word"));
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();

    // Check if isogram
    // check if right num of letters

    if (Input == HiddenWord)
    {
        PrintLine(TEXT("You Win!"));
    }
    else
    {
        PrintLine(TEXT("You Lose!"));
        // remove one life
        // check if lives == 0
    }

    //     check if lives > 0
    // if yes GuessAgain
    // Show lives left
    // If no show GameOver and hidden word
    // prompt to play again
    // check user input
    // if yes, RestartGame
    // If no, quit
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("unreal");
    Lives = 4;
}

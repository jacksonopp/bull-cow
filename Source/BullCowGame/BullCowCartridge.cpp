// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    // if the game is over, ClearScreen(), SetupGame()
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
        return;
    }
    ProcessGuess(Input);

    // Check if not isogram

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
    // Welcome player
    PrintLine(TEXT("Welcome to Bull Cows!"));

    HiddenWord = TEXT("cakes");
    Lives = HiddenWord.Len();
    bGameOver = false;

    // FIXME: DEBUG LINE
    PrintLine(TEXT("---DEBUG---\nThe hidden word is %s.\nIt is %i characters long.\n---DEBUG---"), *HiddenWord, HiddenWord.Len(), Lives);

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives!"), Lives);
    PrintLine(TEXT("Type in your guess.\nPress enter to continue..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again"));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (false)
    {
        // TODO: implement this and return
    }

    // check if wrong num of letters
    if (Guess.Len() != HiddenWord.Len())
    {
        ClearScreen();
        // Do something
        PrintLine(TEXT("The hidden word is %i characters long. Try Again."), HiddenWord.Len());
        PrintLine(TEXT("You have %i lives remaining"), Lives);
        return;
    }

    // check the player guess
    if (Guess == HiddenWord)
    {
        ClearScreen();
        PrintLine(TEXT("You win!"));
        EndGame();
    }
    else
    {
        // remove one life
        --Lives;
        // check if lives == 0
        ClearScreen();
        PrintLine(TEXT("You lost one life.\nYou have %i lives remaining!"), Lives);
    }

    if (Lives <= 0)
    {
        PrintLine(TEXT("Game over!"));
        EndGame();
        return;
    }
}
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

    // If they're out of lives
    if (Lives <= 0)
    {
        EndGame(false);
        return;
    }
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

void UBullCowCartridge::EndGame(bool bIsGameWon)
{
    bGameOver = true;
    ClearScreen();
    if (bIsGameWon)
    {
        PrintLine(TEXT("Congratulations, you win!"));
        PrintLine(TEXT("Press enter to play again"));
        return;
    }
    PrintLine(TEXT("You have no lives left!"));
    PrintLine(TEXT("The hidden word was %s"), *HiddenWord);
    PrintLine(TEXT("Press enter to play again"));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    // Check if they guessed correctly
    if (Guess == HiddenWord)
    {
        ClearScreen();
        PrintLine(TEXT("You win!"));
        EndGame(true);
        return;
    }
    // check if wrong num of letters
    if (Guess.Len() != HiddenWord.Len())
    {
        ClearScreen();
        PrintLine(TEXT("The hidden word is %i characters long. Try Again."), HiddenWord.Len());
        PrintLine(TEXT("You have %i lives remaining"), Lives);
        return;
    }

    // Check if is not isogram FIXME:
    if (!IsIsogram(Guess))
    {
        // ClearScreen();
        PrintLine(TEXT("No repeating letters, guess again"));
        return;
    }

    // Show bulls and cows

    // They guessed wrong
    // remove one life
    --Lives;
    // check if lives == 0
    ClearScreen();
    PrintLine(TEXT("You lost one life.\nYou have %i lives remaining!"), Lives);
}

bool UBullCowCartridge::IsIsogram(FString Word) const
{
    for (int32 i = 0; i < Word.Len(); i++)
    {
        PrintLine(TEXT("%c"), Word[j]);
    }

    // Loop through each letter of Word
    // for (int32 i = 0; i < Word.Len() - 1; i++)
    // {
    //     // Loop through word again
    //     for (int32 j = 0; j < Word.Len() - 1; j++)
    //     {
    //         if (i != j && Word[i] == Word[j])
    //         {
    //             return false;
    //         }
    //     }
    // }
    return true;
}
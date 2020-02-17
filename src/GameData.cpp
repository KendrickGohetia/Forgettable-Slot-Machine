#include "GameData.h"

void GameData::incBet() {
	playerBet++;

}

void GameData::decBet() {
	playerBet--;

}

int GameData::getBet() {
	return playerBet;

}

void GameData::incCredit() {
	playerCredit++;

}

void GameData::decCredit() {
	playerCredit--;

}

int GameData::getCredit() {
	return playerCredit;

}
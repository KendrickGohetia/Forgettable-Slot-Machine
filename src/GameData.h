#pragma once
#ifndef __GAME_DATA__
#define __GAME_DATA__

class GameData {
public:
	void incBet();
	void decBet();
	int getBet();

	void incCredit();
	void decCredit();
	int getCredit();
private:
	

	int playerBet;
	int playerCredit;
	

};

#endif /* defined (__GAME_DATA__) */
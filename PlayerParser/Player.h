#pragma once
class Player
{
	public:
		const char* name;
		int wins;
		int losses;
		const char* lastFive[5];
		Player(const char* n, int w, int l);
		void addLast(const char* playerName);
	private:
		int top;

};


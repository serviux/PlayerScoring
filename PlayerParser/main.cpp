

#pragma warning(disable : 4996)
#include<cstdio>
#include<list>

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"

#include "Player.h"


using namespace rapidjson;

int main() 
{
	
	FILE* f = fopen("C:\\Users\\Josh\\Desktop\\league_data_20200207123919.json", "rb");
	char readBuffer[65536];
	FileReadStream is(f, readBuffer, sizeof(readBuffer));
	
	std::list<Player*> players;
	Document d;
	d.ParseStream(is);
	if(d.HasMember("players"))
	{
		const Value& val = d["players"];
		for (SizeType i = 0; i < val.Size(); i++) {
			Player* p = new Player(
				val[i]["name"].GetString(),
				val[i]["wins"].GetInt(),
				val[i]["losses"].GetInt());

			printf("Name:%s \tWins: %d \tLosses: %d \n",
				val[i]["name"].GetString(),
				val[i]["wins"].GetInt(),
				val[i]["losses"].GetInt());

			const Value& last_five = val[i]["last_five"];
			printf("Last Five: ");
			for (auto& v : val[i]["last_five"].GetArray()) {
				printf("%s, ", v.GetString());
				p->addLast(v.GetString());
			}

			printf("\n");

			players.push_front(p);
		}
		
	}
	fclose(f);

	return 0;
}
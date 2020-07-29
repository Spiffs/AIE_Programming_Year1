




class FileDb
{
public:

	FileDb()
	{
		
	}
	
	~FileDb()
	{
		delete[] m_players;
	}
	
	void AddPlayer(const char *name, int score)
	{
		int newSize = m_numPlayers + 1;
		Player *newPlayerArr = new Players[newSize];
		
		// copy old player data to new player data
		for(int i=0; i<m_numPlayers; i++)
		{
			newPlayerArr[i] = m_players[i];
		}
		
		// create the new player
		newPlayerArr[newSize-1].name = name;
		newPlayerArr[newSize-1].score = score;
		
		// delete the old array
		delete[] m_players;
		
		// re-assign the players array
		m_players = newPlayerArr;
		m_numPlayers = newSize;
		
	}
	
	void SaveToFile()
	{
		
	}
	
	void Sort()
	{
		
	}

protcted:
private:

	Player *m_players = nullptr;
	int m_numPlayers = 0;
	
	
	
	
	
	
	
}



// ========================

template<class T>
class DynamicArray
{
public:

	void Push(const T& item);
	void Pop();

protected:
private:

	T *m_data = nullptr;
	int m_numItems = 0;

};


class DynamicArray_____PLAYER
{
public:

	void Push(const Player& item);
	void Pop();
	
	T& Get(int index);
		
	void Sort();

protected:
private:

	Player *m_data = nullptr;
	int m_numItems = 0;

};



DynamicArray<Player> m_players;

m_players[3]


std::list<int> myIntList;
std::vector<Player *> players;
std::map<std::string, int> map;

map["one"] = 1;







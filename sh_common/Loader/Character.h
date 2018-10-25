#pragma once

namespace ExcelData
{

class Character
{
public:
	Character()
	{
		memset(&m_Wis, 0, sizeof(m_Wis));

		memset(&m_Str, 0, sizeof(m_Str));

		memset(&m_Speed, 0, sizeof(m_Speed));

		memset(&m_Sight, 0, sizeof(m_Sight));

		memset(&m_Phy, 0, sizeof(m_Phy));

		memset(&m_Luck, 0, sizeof(m_Luck));

		memset(&m_Int, 0, sizeof(m_Int));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_Dex, 0, sizeof(m_Dex));

		memset(&m_Decide_Cooltime, 0, sizeof(m_Decide_Cooltime));

		memset(&m_Decide, 0, sizeof(m_Decide));

		memset(&m_Cost, 0, sizeof(m_Cost));

		memset(&m_Agi, 0, sizeof(m_Agi));

		memset(&m_Action_Cooltime, 0, sizeof(m_Action_Cooltime));

	}

	int& WisReference()
	{
		return m_Wis;
	}

	int Wis() const
	{
		return m_Wis;
	}

	void Wis(const int& _Wis)
	{
		m_Wis = _Wis;
	}

	int& StrReference()
	{
		return m_Str;
	}

	int Str() const
	{
		return m_Str;
	}

	void Str(const int& _Str)
	{
		m_Str = _Str;
	}

	int& SpeedReference()
	{
		return m_Speed;
	}

	int Speed() const
	{
		return m_Speed;
	}

	void Speed(const int& _Speed)
	{
		m_Speed = _Speed;
	}

	int& SightReference()
	{
		return m_Sight;
	}

	int Sight() const
	{
		return m_Sight;
	}

	void Sight(const int& _Sight)
	{
		m_Sight = _Sight;
	}

	int& PhyReference()
	{
		return m_Phy;
	}

	int Phy() const
	{
		return m_Phy;
	}

	void Phy(const int& _Phy)
	{
		m_Phy = _Phy;
	}

	std::wstring& NameReference()
	{
		return m_Name;
	}

	std::wstring Name() const
	{
		return m_Name;
	}

	void Name(const std::wstring& _Name)
	{
		m_Name = _Name;
	}

	int& LuckReference()
	{
		return m_Luck;
	}

	int Luck() const
	{
		return m_Luck;
	}

	void Luck(const int& _Luck)
	{
		m_Luck = _Luck;
	}

	int& IntReference()
	{
		return m_Int;
	}

	int Int() const
	{
		return m_Int;
	}

	void Int(const int& _Int)
	{
		m_Int = _Int;
	}

	int& IndexReference()
	{
		return m_Index;
	}

	int Index() const
	{
		return m_Index;
	}

	void Index(const int& _Index)
	{
		m_Index = _Index;
	}

	std::wstring& ImageReference()
	{
		return m_Image;
	}

	std::wstring Image() const
	{
		return m_Image;
	}

	void Image(const std::wstring& _Image)
	{
		m_Image = _Image;
	}

	int& DexReference()
	{
		return m_Dex;
	}

	int Dex() const
	{
		return m_Dex;
	}

	void Dex(const int& _Dex)
	{
		m_Dex = _Dex;
	}

	int& Decide_CooltimeReference()
	{
		return m_Decide_Cooltime;
	}

	int Decide_Cooltime() const
	{
		return m_Decide_Cooltime;
	}

	void Decide_Cooltime(const int& _Decide_Cooltime)
	{
		m_Decide_Cooltime = _Decide_Cooltime;
	}

	int& DecideReference()
	{
		return m_Decide;
	}

	int Decide() const
	{
		return m_Decide;
	}

	void Decide(const int& _Decide)
	{
		m_Decide = _Decide;
	}

	int& CostReference()
	{
		return m_Cost;
	}

	int Cost() const
	{
		return m_Cost;
	}

	void Cost(const int& _Cost)
	{
		m_Cost = _Cost;
	}

	int& AgiReference()
	{
		return m_Agi;
	}

	int Agi() const
	{
		return m_Agi;
	}

	void Agi(const int& _Agi)
	{
		m_Agi = _Agi;
	}

	int& Action_CooltimeReference()
	{
		return m_Action_Cooltime;
	}

	int Action_Cooltime() const
	{
		return m_Action_Cooltime;
	}

	void Action_Cooltime(const int& _Action_Cooltime)
	{
		m_Action_Cooltime = _Action_Cooltime;
	}

private:
	int m_Wis;
	int m_Str;
	int m_Speed;
	int m_Sight;
	int m_Phy;
	std::wstring m_Name;
	int m_Luck;
	int m_Int;
	int m_Index;
	std::wstring m_Image;
	int m_Dex;
	int m_Decide_Cooltime;
	int m_Decide;
	int m_Cost;
	int m_Agi;
	int m_Action_Cooltime;
};

class CharacterData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		Character Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/Character.XML");
		if( false == parser.read_file(L"./XML/Character.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/Character.XML");
			return false;
		}

		if ( false == parser.execute(L"/CharacterList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /CharacterList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"Action_Cooltime", Instance.Action_CooltimeReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Action_CooltimeReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Agi", Instance.AgiReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.AgiReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Cost", Instance.CostReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.CostReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Decide", Instance.DecideReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.DecideReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Decide_Cooltime", Instance.Decide_CooltimeReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Decide_CooltimeReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Dex", Instance.DexReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.DexReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Image", Instance.ImageReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ImageReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Index", Instance.IndexReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.IndexReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Int", Instance.IntReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.IntReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Luck", Instance.LuckReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.LuckReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Name", Instance.NameReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.NameReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Phy", Instance.PhyReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.PhyReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Sight", Instance.SightReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.SightReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Speed", Instance.SpeedReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.SpeedReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Str", Instance.StrReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.StrReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Wis", Instance.WisReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.WisReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, Character>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, Character& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, Character>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, Character> m_Map;
};

__declspec(selectany) CharacterData CharacterDataInstance;

} // ExcelData


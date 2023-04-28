// BEFORE
#include <iostream>
using namespace std;
//class Image
//{
//	int m_id;
//	static int s_next;
//public:
//	Image()
//	{
//		m_id = s_next++;
//		cout << "   $$ ctor: " << m_id << '\n';
//	}
//	~Image()
//	{
//		cout << "   dtor: " << m_id << '\n';
//	}
//	void draw()
//	{
//		cout << "   drawing image " << m_id << '\n';
//	}
//};
//int Image::s_next = 1;
//
//int main()
//{
//	Image images[5];
//
//	for (int i; true;)
//	{
//		cout << "Exit[0], Image[1-5]: ";
//		cin >> i;
//		if (i == 0)
//			break;
//		images[i - 1].draw();
//	}
//}

//--------------------------------------------
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//--------------------------------------------

//// AFTER
class RealImage
{
	int m_id;
public:
	RealImage(int i)
	{
		m_id = i;
		cout << "   $$ ctor: " << m_id << '\n';
	}
	~RealImage()
	{
		cout << "   dtor: " << m_id << '\n';
	}
	void draw()
	{
		cout << "   drawing image " << m_id << '\n';
	}
};

// 1. Класс-обертка с "дополнительным уровнем косвенности"
class Image // proxy
{
	// 2. Класс-обертка содержит указатель на реальный класс
	RealImage * m_the_real_thing;
	int m_id;
	static int s_next;
public:
	Image()
	{
		m_id = s_next++;
		// 3. Инициализируется нулевым значением
		m_the_real_thing = nullptr;
	}
	~Image()
	{
		delete m_the_real_thing;
	}
	void draw()
	{
		// 4. Реальный объект создается при поступлении 
		//    запроса "на первом использовании"
		if (!m_the_real_thing)
			m_the_real_thing = new RealImage(m_id);
		// 5. Запрос всегда делегируется реальному объекту
		m_the_real_thing->draw();
	}
};
int Image::s_next = 1;

int main()
{
	Image images[5];

	for (int i; true;)
	{
		cout << "Exit[0], Image[1-5]: ";
		cin >> i;
		if (i == 0)
			break;
		images[i - 1].draw();
	}
}
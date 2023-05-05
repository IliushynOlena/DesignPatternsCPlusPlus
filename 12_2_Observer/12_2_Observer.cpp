#include <iostream>
#include "Car.h"
#include "Buyer.h"

using namespace std;

int main()
{
	// создали объект машины с начальной ценой 100 000
	Car* bmw = new Car("bmw X9", 100000);

	// создали объекты потенциальных покупателей машины
	UkrainianBuyer* firstBuyer = new UkrainianBuyer("Petro Mikolaenko");
	UkrainianBuyer* secondBuyer = new UkrainianBuyer("Oleg Kononenko");

	// покупатели интересуются конкретной машиной
	bmw->Attach(firstBuyer);
	bmw->Attach(secondBuyer);

	// снижение цены машины, заинтересованные покупатели тут же узнают об этом
	bmw->SetPrice(80000);
	bmw->SetPrice(70000);

	bmw->Detach(secondBuyer);

	bmw->SetPrice(65000);
	bmw->SetPrice(60000);

	delete firstBuyer;
	delete secondBuyer;
	delete bmw;

	system("pause");
	return 0;
}
#include "classes.h"

int main() {

	Man Ali;
	Man Veli; 
	Man Hasan;
	Woman Ayse;
	Woman Fatma;
	Woman Hayriye;

	bool isAllEngaged = false;
	int population = 3;

	std::vector<Man>::iterator itm;
	std::vector<Woman>::iterator itw;

	Ali.setName("Ali");
	Veli.setName("Veli");
	Hasan.setName("Hasan");
	Ayse.setName("Ayse");
	Fatma.setName("Fatma");
	Hayriye.setName("Hayriye");

	Ali.setPrefList(Hayriye);
	Ali.setPrefList(Fatma);
	Ali.setPrefList(Ayse);
	std::vector<Woman> womanList = Ali.getPrefList();

	Veli.setPrefList(Ayse);
	Veli.setPrefList(Hayriye);
	Veli.setPrefList(Fatma);

	Hasan.setPrefList(Fatma);
	Hasan.setPrefList(Ayse);
	Hasan.setPrefList(Hayriye);

	Ayse.setPrefList(Hasan);
	Ayse.setPrefList(Ali);
	Ayse.setPrefList(Veli);
	std::vector<Man> manList = Ayse.getPrefList();

	Fatma.setPrefList(Ali);
	Fatma.setPrefList(Veli);
	Fatma.setPrefList(Hasan);

	Hayriye.setPrefList(Hasan);
	Hayriye.setPrefList(Veli);
	Hayriye.setPrefList(Ali);

	while (!isAllEngaged)
	{
		// Every morning, women in the village left a message on their the (next-)best choices.
		for (itw = womanList.begin(); itw != womanList.end(); ++itw)
		{
			Woman woman = *itw;
			bool st = woman.getStatus();
			std::cout << woman.getName() << " " << st << std::endl;
			if (!st)
			{
				size_t round = woman.getRound();
				std::vector<Man> prefList = woman.getPrefList();
				Man nextOnTheList = prefList.at(round);
				nextOnTheList.setMessageBox(woman);
				++round;
				woman.setRound(round);
			}
		}

		// Every afternoon men check their message box and reply according to their preference list.
		for (itm = manList.begin(); itm != manList.end(); ++itm)
		{
			Man man = *itm;
			std::vector<Woman> messageBox = man.getMessageBox();
			if (messageBox.size() != 0)
			{
				std::vector<Woman> prefList = man.getPrefList();
				bool st = man.getStatus();
				if (!st)
				{
					// Kendine teklif getiren kizlara bakacak. Listede kendi nisanlisindan daha ustte biri varsa nisan atip yeni adayla nisanlanacak. 
				}
				else
				{
					// Kendine teklif getiren kizlara bakacak. Listede en ust siradaki adayla nisanlanacak. 
					for (itw = messageBox.begin(); itw != messageBox.end(); ++itw)
					{
						Woman woman = *itw;
						int pos1 = std::find(messageBox.begin(), messageBox.end(), woman) - messageBox.begin();
					}

					man.setStatus(true);
				}
			}
		}


		// Checking marital status of the village at the end of the day.
		int numOfCouples = 0;
		for (itm = manList.begin(); itm != manList.end(); ++itm) 
		{
			Man man = *itm;
			bool st = man.getStatus();
			std::cout << man.getName() << " " << st << std::endl;
			if (st)
			{
				++numOfCouples;
			}
		}
		if (numOfCouples == population)
		{
			isAllEngaged = true;
		}

		std::cout <<  numOfCouples << std::endl;
	}


	//std::cout << Ali.getName();
	//std::cout << Veli.getName();
	//std::cout << Hasan.getName();
	//std::cout << Ayse.getName();
	//std::cout << Fatma.getName();
	//std::cout << Hayriye.getName();

	int a;
	std::cin >> a;


	return 0;
}
#include <fstream>
#include "chest.h"

namespace ygo {
	Chest::Chest() :
		unlimited(true) {
	}
	void Chest::LoadFromFile(std::string filename) {
		std::ifstream ifs(filename);
		if (ifs) {
			int cardId;
			int cardQuantity;
			unlimited = false;
			while (ifs >> cardId >> cardQuantity) {
				unlocked_cards[cardId] = cardQuantity;
			}
		}
	}
	bool Chest::IsUnlimited() {
		return unlimited;
	}
	bool Chest::ContainsCard(int cardId) {
		if (unlimited) {
			return true;
		}
		return unlocked_cards[cardId] > 0;
	}
	int Chest::GetCardAmount(int cardId) {
		return unlocked_cards[cardId];
	}
}

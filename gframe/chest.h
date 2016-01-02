#ifndef CHEST_H
#define CHEST_H

#include <unordered_map>
#include <string>

namespace ygo {
	class Chest {
	private:
		std::unordered_map<int, int> unlocked_cards;
		bool unlimited;

	public:
		Chest();
		void LoadFromFile(std::string filename);
		bool IsUnlimited();
		bool ContainsCard(int cardId);
		int GetCardAmount(int cardId);
	};
}

#endif //CHEST_H

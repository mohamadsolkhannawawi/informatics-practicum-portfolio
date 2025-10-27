#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int INF = 1e9;

void createDependencyOrder(int currentRoom, vector<vector<pair<int, int>>>& tunnels, 
                      vector<bool>& visited, stack<int>& orderedRooms) {
    visited[currentRoom] = true;
    
    for (auto& tunnel : tunnels[currentRoom]) {
        int nextRoom = tunnel.first;
        if (!visited[nextRoom]) {
            createDependencyOrder(nextRoom, tunnels, visited, orderedRooms);
        }
    }
    
    orderedRooms.push(currentRoom);
}

int main() {
    int roomCount, startRoom, finishRoom;
    cin >> roomCount >> startRoom >> finishRoom;
    
    vector<int> goldValue(roomCount + 1);
    for (int i = 1; i <= roomCount; i++) {
        cin >> goldValue[i];
    }
    
    int tunnelCount;
    cin >> tunnelCount;
    
    vector<vector<pair<int, int>>> tunnels(roomCount + 1);
    for (int i = 0; i < tunnelCount; i++) {
        int fromRoom, toRoom, hasMonster;
        cin >> fromRoom >> toRoom >> hasMonster;
        tunnels[fromRoom].push_back({toRoom, hasMonster});
    }
    
    int coinCount;
    cin >> coinCount;
    
    vector<bool> hasCoin(roomCount + 1, false);
    for (int i = 0; i < coinCount; i++) {
        int roomWithCoin;
        cin >> roomWithCoin;
        hasCoin[roomWithCoin] = true;
    }
    
    vector<bool> visited(roomCount + 1, false);
    stack<int> orderedRooms;
    
    createDependencyOrder(startRoom, tunnels, visited, orderedRooms);
    
    vector<int> processingOrder;
    while (!orderedRooms.empty()) {
        processingOrder.push_back(orderedRooms.top());
        orderedRooms.pop();
    }
    
    vector<vector<int>> maxGoldDP(roomCount + 1, vector<int>(roomCount + 1, -1));
    maxGoldDP[startRoom][hasCoin[startRoom] ? 1 : 0] = goldValue[startRoom];
    
    for (int roomIndex : processingOrder) {
        for (int currentCoins = 0; currentCoins <= roomCount; currentCoins++) {
            if (maxGoldDP[roomIndex][currentCoins] == -1) continue;
            
            for (auto& tunnel : tunnels[roomIndex]) {
                int nextRoom = tunnel.first;
                int monsterPresent = tunnel.second;
                
                if (monsterPresent == 1 && currentCoins == 0) continue;
                
                int availableCoins = currentCoins - (monsterPresent == 1 ? 1 : 0);
                int newCoins = availableCoins + (hasCoin[nextRoom] ? 1 : 0);
                
                newCoins = min(newCoins, roomCount);
                
                int newGold = maxGoldDP[roomIndex][currentCoins] + goldValue[nextRoom];
                if (maxGoldDP[nextRoom][newCoins] < newGold) {
                    maxGoldDP[nextRoom][newCoins] = newGold;
                }
            }
        }
    }
    
    int maxPossibleGold = -INF; 
    for (int i = 0; i <= roomCount; i++) {
        if (maxGoldDP[finishRoom][i] != -1) {
            maxPossibleGold = max(maxPossibleGold, maxGoldDP[finishRoom][i]);
        }
    }

    if (maxPossibleGold == -INF) {
        cout << - 1 << endl;
    } else {
        cout << maxPossibleGold;
    }
    
    return 0;
}
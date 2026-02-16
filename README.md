# Simple HashID Module & Addons 🎫

The module adds a client lua function GetHashID() that returns the computer's HWID encrypted in SHA256.

# Addons
## ⚙ HashIDLite
Simply checks if the player has the module installed. It serves as the foundation for other addons. Adds commands such as:
gethashid *nickname* – Returns the player's HashID based on their nickname. Requires admin privileges.
gethashidall – Returns the HashID of all players on the server. Requires admin privileges.

## 🎟 HashIDLog 
Checks if the player has the module installed and associates their SteamID64 with their HashID. If a player somehow changes their SteamID64 but retains the same HashID, the server will not allow them to join. Data about linked HashIDs is stored in garrysmod/data/hashidloglist.txt.
Adds commands such as:
hashidrm *hashid* – Removes a HashID from the "logged" table and from hashidloglist.txt. Requires admin privileges.
hashidwrite – Overwrites hashidloglist.txt. Requires superadmin privileges.
hashidreload – Reloads the "logged" table. Requires superadmin privileges.

## 🚫 HashIDBan
Checks if the player has the module installed and adds a simple ban system based on HashID. If a player somehow changes their SteamID64 but retains the same HashID, the server will not allow them to join if they are banned by HashID. Data about HashID bans is stored in garrysmod/data/hashidbanlist.txt.
Adds commands such as:
banhashid *nickname* – Bans a player by their HashID with a specified reason and duration. Requires admin privileges.
unbanhashid *hashid* – Unbans a player by their HashID. Requires admin privileges.
hashidwrite – Overwrites hashidbanlist.txt. Requires superadmin privileges.
hashidreload – Reloads the "banned" table. Requires superadmin privileges.

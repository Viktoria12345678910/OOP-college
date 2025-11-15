i wanna do tabs and something like obsidian where you have diffrent libraries... Nah this sounds unneccesarry i can just do it with section like for fantasy or self published or smut or stuff like that

i dont think auth is necessary. Maybe i could do it like in obsidian, you dont have to log in but you can for sync, but i aint sure. Or maybe i should add abilyty to add several accounts to hide ceirtan parts of your library from other users for example hide smut from kids
database structure:
1. sections[section ID,name of section,abbreviation, description, path, number of books in section, groups that have access(default = all) //type of medium//]
2. books[book ID, medium(paper, e-book, audiobook), title, author, genre, rating, description, read BOOL, view rights(everyvone, just me, choose group of users to view, choose users to have access), cover]
3. users[user ID, user name, passwordHash, salt, created at, last login, groups user is apart of //reading statistics//]
4. Settings[appVersion, RunBefore, interfaceBackgroundColor, accentColor, backgoundMusic BOOL, backgroundMusicFile FILE, sounds BOOL, sound pack]
5. Groups[id, groupName, users LIST OF USERNAMES] 
i will need the foliwing pages:
- [x] new book
- [x] new account
- [x] new section
i have an internal debate on whether to make a home page or not

//...// - means that whatever is in between would be possibly implemented in the future


Stuff to return to:
1. https://doc.qt.io/qt-6/qframe.html #makeItPretier
2. https://doc.qt.io/qt-6/qtableview.html #catalog
3. https://forum.qt.io/topic/114072/display-values-from-database-to-qcombobox #sections
4. https://www.geeksforgeeks.org/ethical-hacking/what-is-salted-password-hashing/ #auth
5. https://doc.qt.io/qt-6/qtabwidget.html general like | docs on my chosen interface

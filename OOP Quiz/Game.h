#pragma once
namespace Header_files {
	namespace Game_files {
		using namespace Quiz_functions;
		using namespace Quiz_files;
		using namespace User_files;
		using namespace File_Handling;


		void game()
		{
			cout << boolalpha;
			vector<string>Files = { "Player.txt","Admin.txt","Quiz.txt" };

			vector<Player*> players;
			vector<Admin*> admins;
			vector<Quiz*> quizzes;



			try
			{
				players = load_players(Files[0]);

			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}

			try
			{
				admins = load_admins(Files[1]);

			}
			catch (const std::exception ex)
			{
				cout << ex.what() << endl;
			}

			try
			{

				quizzes = load_quizzes(Files[2]);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}



			Command start_screen;
			start_screen.commands.push_back("Start");
			start_screen.commands.push_back("Exit");

			bool game = false;
			bool choice;

			system("cls");

			while (!game)
			{
			start:

				cout << start_screen;
				choice = cursorControl(start_screen);

				if (choice)
				{
					switch (start_screen.commandIndex)
					{
					case 0:

						game = true;
						break;

					case 1:
						system("cls");
						cout << "\n\n\n\n\n\t\t\t\t\t======  GOOD BYE  ======\n\n\n\n";
						system("pause");
						exit(0);
						break;

					}
				}
			}


			game = false;



			Command start;
			start.commands.push_back("Sign up");
			start.commands.push_back("Log in");
			start.commands.push_back("Continue as a Guest");
			start.commands.push_back("Back");

			Command signUp;
			signUp.commands.push_back("Sign up as Player");
			signUp.commands.push_back("Sign up as Admin");
			signUp.commands.push_back("Back");

			Command LogIn;
			LogIn.commands.push_back("Log in as Player");
			LogIn.commands.push_back("Log in as Admin");
			LogIn.commands.push_back("Back");


			string username;
			string password;


			User* user = nullptr;
		SignUP:
			bool isAdmin = false;
			bool isGuest = false;
			bool previous = false;

			while (!game)
			{
				cout << start;

				choice = cursorControl(start);

				if (choice)
				{
					switch (start.commandIndex)
					{
					case 0:
						system("cls");
						while (!previous)
						{
							cout << signUp;
							choice = cursorControl(signUp);

							if (choice)
							{
								switch (signUp.commandIndex)
								{

								case 0:
									cout << "\t\t\t\t PLAYER SIGN UP\n\n";
									cout << "\nEnter your username: ";
									getline(cin, username);
									cout << "\nEnter your password: ";
									hidePassword(password);
									//getline(cin, password);

									if (check_username(players, admins, username))
									{
										cout << "\nThis username is already used\n";
										system("pause");
										system("cls");
										continue;
									}
									try
									{
										user = new Player(username, password);
										players.push_back(dynamic_cast<Player*> (user));
									}
									catch (const std::exception& ex)
									{
										cout << ex.what() << endl;
										system("pause");
										system("cls");
										continue;
									}

									game = true;
									previous = true;
									break;

								case 1:
									cout << "\t\t\t\t Admin SIGN UP\n\n";
									cout << "\nEnter your username: ";
									getline(cin, username);
									cout << "\nEnter your password: ";
									hidePassword(password);
									//getline(cin, password);

									if (check_username(players, admins, username))
									{
										cout << "\nThis username is already used\n";
										system("pause");
										system("cls");
										continue;
									}
									try
									{
										user = new Admin(username, password);
										isAdmin = true;

										admins.push_back(dynamic_cast<Admin*> (user));
									}
									catch (const std::exception& ex)
									{
										cout << ex.what() << endl;
										system("pause");
										system("cls");
										continue;
									}

									game = true;
									previous = true;
									break;
								case 2:
									previous = true;


								}
							}


						}
						previous = false;
						break;

					case 1:
						system("cls");
						while (!previous)
						{
							cout << LogIn;
							choice = cursorControl(LogIn);
							if (choice)
							{
								switch (LogIn.commandIndex)
								{
								case 0:

									system("cls");
									cout << "\nEnter your username : ";
									getline(cin, username);
									cout << "\nEnter your password: ";
									hidePassword(password);
									//getline(cin, password);

									user = findPlayer(players, username, password);
									if (user == nullptr)
									{
										cout << "Player not found! Pls Sign up our quiz!\n";
										system("pause");
										system("cls");
										continue;
									}

									previous = true;
									game = true;
									break;

								case 1:
									system("cls");
									cout << "Enter your username: ";
									getline(cin, username);
									cout << "\nEnter your password: ";
									hidePassword(password);
									//getline(cin, password);

									user = findAdmin(admins, username, password);
									if (user == nullptr)
									{
										cout << "Admin not found! Pls Sign up our quiz!\n";
										system("pause");
										system("cls");
										continue;
									}
									isAdmin = true;

									previous = true;
									game = true;
									break;

								case 2:
									previous = true;

								}

							}
						}

						previous = false;
						break;

					case 2:
						isGuest = true;
						game = true;
						break;

					case 3:
						goto start;


					}
				}
			}
			previous = false;
			game = false;







			Quiz* quiz_result = nullptr;
			Quiz* test_quiz = nullptr;

			Command prev_quizzes;
			prev_quizzes.commands.push_back("Exit\n");

			Command Admin_c;
			Admin_c.commands.push_back("Create Quiz");
			Admin_c.commands.push_back("Test Quiz");
			Admin_c.commands.push_back("Leadear Board (Top 10)");
			Admin_c.commands.push_back("Back to sign up screen");
			Admin_c.commands.push_back("Exit");

			Command Player_c;
			Player_c.commands.push_back("Play Quiz");
			Player_c.commands.push_back("Leadear Board (Top 10)");
			Player_c.commands.push_back("Back to sign up screen");
			Player_c.commands.push_back("Exit");

			Command Guest_c;
			Guest_c.commands.push_back("Play Quiz");
			Guest_c.commands.push_back("Back to sign up screen");
			Guest_c.commands.push_back("Exit");

			Command Final_screen_Player;
			Final_screen_Player.commands.push_back("See the score");
			Final_screen_Player.commands.push_back("See corrects");
			Final_screen_Player.commands.push_back("See falses");
			Final_screen_Player.commands.push_back("See unanswered");
			Final_screen_Player.commands.push_back("Save statistics");
			Final_screen_Player.commands.push_back("Exit");
			
			Command Final_screen_Admin;
			Final_screen_Admin.commands.push_back("See corrects");
			Final_screen_Admin.commands.push_back("See falses");
			Final_screen_Admin.commands.push_back("See unanswered");
			Final_screen_Admin.commands.push_back("Exit");

			Command Final_screen_Guest;
			Final_screen_Guest.commands.push_back("See the score");
			Final_screen_Guest.commands.push_back("See corrects");
			Final_screen_Guest.commands.push_back("See falses");
			Final_screen_Guest.commands.push_back("See unanswered");
			Final_screen_Guest.commands.push_back("Exit");

			if (isAdmin)
			{
				system("cls");
				while (!game)
				{

					show_quiz_c(prev_quizzes, quizzes);


					cout << Admin_c;
					choice = cursorControl(Admin_c);

					if (choice)
					{
						switch (Admin_c.commandIndex)
						{
						case 0:
							try
							{
								test_quiz = createQuiz();
							}
							catch (const std::exception& ex)
							{
								cout << ex.what() << endl;
								system("pause");
								system("cls");
								continue;
							}

							if (test_quiz == nullptr)
								continue;

							quizzes.push_back(new Quiz(*test_quiz));

							break;

						case 1:
							system("cls");
							while (!previous)
							{
								if (prev_quizzes.commands.size() == 0)
								{
									cout << "Quizzes not exist! Pls create new quiz!\n";
									system("pause");
									system("cls");
									break;
								}
								cout << prev_quizzes;
								choice = cursorControl(prev_quizzes);
								if (choice)
								{
									if (prev_quizzes.commandIndex == 0)
										break;

									quiz_result = find_quiz(quizzes, prev_quizzes.commands[prev_quizzes.commandIndex]);

									random_quiz(quiz_result);
									quiz_result = play_q(quiz_result);
									system("cls");
									while (!previous)
									{
										cout << Final_screen_Admin;
										choice = cursorControl(Final_screen_Admin);
										if (choice)
										{
											switch (Final_screen_Admin.commandIndex)
											{
											case 0:
												system("cls");
												cout << "\n======  Corrects  ======\n";
												quiz_result->show_corrects();
												system("pause");
												system("cls");
												break;
											case 1:
												system("cls");
												cout << "\n======  Falses  ======\n";
												quiz_result->show_falses();
												system("pause");
												system("cls");
												break;

											case 2:
												system("cls");
												cout << "\n======  Neutrals  ======\n";
												quiz_result->show_neutral();
												system("pause");
												system("cls");
												break;

											case 3:
												previous = true;
											}
										}
									}
									previous = false;
								}
							}

							break;

						case 2:
							system("cls");
							cout << "\n=========  Leadear Board (Top 10)  =========\n\n";
							seeAllPlayersResults(players);
							system("pause");
							system("cls");
							break;

						case 3:
							system("cls");
							goto SignUP;

						case 4:
							system("cls");
							cout << "\n\n\n\n\n\t\t\t\t\t======  GOOD BYE  ======\n\n\n\n";
							Sleep(1500);
							game = true;
						}
					}

					prev_quizzes.commands.clear();
					prev_quizzes.commands.push_back("Exit\n");
				}
			}

			else if (isGuest)
			{
				system("cls");
				while (!game)
				{
					show_quiz_c(prev_quizzes, quizzes);
					cout << Guest_c;
					choice = cursorControl(Guest_c);
					if (choice)
					{
						switch (Guest_c.commandIndex)
						{
						case 0:
							system("cls");
							while (!previous)
							{
								if (quizzes.size() == 0)
								{
									cout << "Quizzes not exist! Pls create new quiz!\n";
									system("pause");
									system("cls");
									break;
								}
								cout << prev_quizzes;
								choice = cursorControl(prev_quizzes);

								if (choice)
								{
									if (prev_quizzes.commandIndex == 0)
										break;

									quiz_result = find_quiz(quizzes, prev_quizzes.commands[prev_quizzes.commandIndex]);

									random_quiz(quiz_result);
									quiz_result = play_q(quiz_result);
									system("cls");


									while (!previous)
									{
										cout << Final_screen_Guest;
										choice = cursorControl(Final_screen_Guest);

										if (choice)
										{
											switch (Final_screen_Guest.commandIndex)
											{
											case 0:
												system("cls");
												cout << "Your score is: " << findScore(quiz_result) <<endl;
												system("pause");
												break;

											case 1:
												system("cls");
												cout << "\n======  Corrects  ======\n";
												quiz_result->show_corrects();
												system("pause");
												system("cls");
												break;
											case 2:
												system("cls");
												cout << "\n======  Falses  ======\n";
												quiz_result->show_falses();
												system("pause");
												system("cls");
												break;

											case 3:
												system("cls");
												cout << "\n======  Neutrals  ======\n";
												quiz_result->show_neutral();
												system("pause");
												system("cls");
												break;


											case 4:
												previous = true;
											}
										}
									}
									previous = false;
								}
							}
							break;

						case 1:
							system("cls");
							goto SignUP;

						case 2:
							system("cls");
							cout << "\n\n\n\n\n\t\t\t\t\t======  GOOD BYE  ======\n\n\n\n";
							Sleep(1500);
							game = true;

						}
					}

					prev_quizzes.commands.clear();
					prev_quizzes.commands.push_back("Exit\n");
				}
			}

			else
			{
				system("cls");
				while (!game)
				{
					show_quiz_c(prev_quizzes, quizzes);

					cout << Player_c;
					choice = cursorControl(Player_c);
					if (choice)
					{
						switch (Player_c.commandIndex)
						{
						case 0:
							system("cls");
							while (!previous)
							{
								if (quizzes.size() == 0)
								{
									cout << "Quizzes not exist! Pls create new quiz!\n";
									system("pause");
									system("cls");

									break;
								}
								cout << prev_quizzes;
								choice = cursorControl(prev_quizzes);
								if (choice)
								{
									if (prev_quizzes.commandIndex == 0)
										break;

									quiz_result = find_quiz(quizzes, prev_quizzes.commands[prev_quizzes.commandIndex]);

									random_quiz(quiz_result);
									quiz_result = play_q(quiz_result);
									system("cls");
									while (!previous)
									{
										cout << Final_screen_Player;
										choice = cursorControl(Final_screen_Player);
										if (choice)
										{
											switch (Final_screen_Player.commandIndex)
											{
											case 0:
												system("cls");
												cout << "Your score is: " << findScore(quiz_result) << endl;
												system("pause");
												system("cls");
												break;

											case 1:
												system("cls");
												cout << "\n======  Corrects  ======\n";
												quiz_result->show_corrects();
												system("pause");
												system("cls");
												break;
											case 2:
												system("cls");
												cout << "\n======  Falses  ======\n";
												quiz_result->show_falses();
												system("pause");
												system("cls");
												break;

											case 3:
												system("cls");
												cout << "\n======  Neutrals  ======\n";
												quiz_result->show_neutral();
												system("pause");
												system("cls");
												break;

											case 4:
												try
												{
													dynamic_cast<Player*>(user)->set_score(findScore(quiz_result));
												}
												catch (const std::exception& ex)
												{
													system("cls");
													cout << ex.what() << endl;
													system("pause");
													system("cls");
													continue;
												}

												system("cls");
												cout << "Saved Successfully !\n";
												system("pause");
												system("cls");
												break;

											case 5:
												previous = true;
											}
										}
									}
									previous = false;
								}
							}

							break;

						case 1:
							system("cls");
							cout << "\n=========  Leadear Board (Top 10)  =========\n\n";
							seeAllPlayersResults(players);
							system("pause");
							system("cls");
							break;

						case 2:
							system("cls");

							goto SignUP;


						case 3:
							system("cls");
							cout << "\n\n\n\n\n\t\t\t\t\t======  GOOD BYE  ======\n\n\n\n";
							Sleep(1500);
							game = true;
						}
					}

					prev_quizzes.commands.clear();
					prev_quizzes.commands.push_back("Exit\n");
				}
			}





			save_players(Files[0], players);
			save_admins(Files[1], admins);
			save_quizzes(Files[2], quizzes);





			for (auto& admin : admins)
				delete admin;

			for (auto& player : players)
				delete player;

			for (auto& quiz : quizzes)
				delete quiz;


		}
	}
}
using System;
using System.Collections.Generic;
using System.Linq;
using System.Xml;

class Program
{
    class Player
    {
        public string Name { get; set; }
        public int Score { get; set; }
        public int Wins { get; set; }

        public Player(string name, int score, int wins)
        {
            Name = name;
            Score = score;
            Wins = wins;
        }
    }

    static void Main()
    {
        SortedList<int, Player> players = new SortedList<int, Player>
        {
            { 1042, new Player("Shadow", 1850, 18) },
            { 1007, new Player("Blaze", 2100, 21) },
            { 1025, new Player("Ghost", 1650, 15) },
            { 1011, new Player("Titan", 2400, 24) },
            { 1038, new Player("Raven", 1950, 19) },
            { 1003, new Player("Storm", 1500, 12) },
            { 1021, new Player("Viper", 2250, 22) }
        };

        // Display all player IDs and names in the SortedList order.
        Console.WriteLine("All Players List:");
        foreach (var player in players.OrderBy(p => p.Key))
        {
            Console.WriteLine($"Id: {player.Key}, Name: {player.Value.Name}");
        }
        Console.WriteLine();


        // Display the name and score of the player with ID 1025.
        Console.WriteLine("Player With ID 1025: ");

        if (players.TryGetValue(1025,out Player player1))
            Console.WriteLine($"Name: {player1.Name}, Score: {player1.Score}");
        Console.WriteLine();


        // Display players with a score greater than 1800, sorted from highest to lowest.
        var filteredPlayers = players.Where(p => p.Value.Score > 1800).OrderByDescending(p => p.Value.Score);

        Console.WriteLine("Players with a score greater than 1800 DESC");

        foreach (var player in filteredPlayers)
            Console.WriteLine($"ID: {player.Key}, Name: {player.Value.Name}, Score: {player.Value.Score}");
        Console.WriteLine();

        // Create and display a collection containing the names of players with at least 20 wins.
        var playersNames = players.Where(p => p.Value.Wins >= 20).Select(p => p.Value.Name).ToList();

        Console.WriteLine("Players with at least 20 wins.");

        foreach (var playerName in playersNames)
        {
            Console.WriteLine(playerName);
        }
        Console.WriteLine();

        // Display the name and ID of the player with the highest score.
        var maxScore = players.Max(p => p.Value.Score);
        var playerWithHighestScore = players.Where(p => p.Value.Score == maxScore);

        Console.WriteLine("Player with the highest score.");
        foreach (var player in playerWithHighestScore)
        {
            Console.WriteLine($"ID: {player.Key}, Name: {player.Value.Name}, Score: {player.Value.Score}");
        }
        Console.WriteLine();


        Console.ReadKey();
    }
}
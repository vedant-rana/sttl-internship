package P92;

import java.util.ArrayList;
import java.util.List;

class Team {
    private String teamName;

    public Team(String teamName) {
        this.teamName = teamName;
    }

    public String getTeamName() {
        return teamName;
    }
}

class Match {
    private Team team1;
    private Team team2;
    private int team1Score;
    private int team2Score;

    public Match(Team team1, Team team2) {
        this.team1 = team1;
        this.team2 = team2;
        this.team1Score = -1; // Default score indicating match not played
        this.team2Score = -1; // Default score indicating match not played
    }

    public Team getTeam1() {
        return team1;
    }

    public Team getTeam2() {
        return team2;
    }

    public int getTeam1Score() {
        return team1Score;
    }

    public int getTeam2Score() {
        return team2Score;
    }

    public void playMatch(int team1Score, int team2Score) {
        this.team1Score = team1Score;
        this.team2Score = team2Score;
    }

    public Team determineWinner() {
        if (team1Score > team2Score) {
            return team1;
        } else if (team2Score > team1Score) {
            return team2;
        } else {
            return null; // Match is a draw
        }
    }
}

class Tournament {
    private List<Team> teams;
    private List<Match> matches;

    public Tournament() {
        this.teams = new ArrayList<>();
        this.matches = new ArrayList<>();
    }

    public void addTeam(Team team) {
        teams.add(team);
    }

    public void createMatches() {
        if (teams.size() % 2 != 0) {
            System.out.println("Tournament requires an even number of teams.");
            return;
        }

        for (int i = 0; i < teams.size(); i += 2) {
            Match match = new Match(teams.get(i), teams.get(i + 1));
            matches.add(match);
        }
    }

    public void conductTournament() {
        for (Match match : matches) {
            // Simulate match play with random scores for demonstration
            int team1Score = (int) (Math.random() * 6); // Score between 0 and 5
            int team2Score = (int) (Math.random() * 6); // Score between 0 and 5

            match.playMatch(team1Score, team2Score);

            System.out.println("Match Result: " + match.getTeam1().getTeamName() + " " +
                    match.getTeam1Score() + " - " + match.getTeam2Score() + " " +
                    match.getTeam2().getTeamName());
            System.out.println("Winner: " + (match.determineWinner() != null ? match.determineWinner().getTeamName() : "Draw"));
            System.out.println("----------------------");
        }
    }

    public Team determineTournamentWinner() {
        List<Team> tournamentWinners = new ArrayList<>();

        for (Match match : matches) {
            tournamentWinners.add(match.determineWinner());
        }

        return new Tournament().conductTournamentHelper(tournamentWinners).get(0);
    }

    private List<Team> conductTournamentHelper(List<Team> winners) {
        if (winners.size() == 1) {
            return winners;
        }

        List<Team> nextRoundWinners = new ArrayList<>();

        for (int i = 0; i < winners.size(); i += 2) {
            Match match = new Match(winners.get(i), winners.get(i + 1));
            nextRoundWinners.add(match.determineWinner());
        }

        return conductTournamentHelper(nextRoundWinners);
    }
}


public class TestTournament {
    public static void main(String[] args) {

        Team team1 = new Team("Team A");
        Team team2 = new Team("Team B");
        Team team3 = new Team("Team C");
        Team team4 = new Team("Team D");


        Tournament tournament = new Tournament();


        tournament.addTeam(team1);
        tournament.addTeam(team2);
        tournament.addTeam(team3);
        tournament.addTeam(team4);


        tournament.createMatches();


        tournament.conductTournament();


        Team tournamentWinner = tournament.determineTournamentWinner();

        System.out.println("Tournament Winner: " + tournamentWinner.getTeamName());
    }
}

import java.util.ArrayList;
import java.util.Scanner;

public class Project5_TristonLuzanta {
	public static void main(String[] args) {
		// Scanner
		Scanner scnr = new Scanner(System.in);

		// Bourbon and Water
		Beverage BandW = new Beverage("Bourbon and Water", 2.0, 140, 6.00);
		// Cosmopolitan
		Beverage Cosmo = new Beverage("Cosmopolitan", 2.0, 212, 7.00);
		// Gin and Tonic
		Beverage GandT = new Beverage("Gin and Tonic", 2.0, 175, 6.00);
		// Mojito
		Beverage Moj = new Beverage("Mojito", 2.0, 242, 6.00);
		// Margarita
		Beverage Marg = new Beverage("Margarita", 2.5, 153, 7.50);
		// Martini
		Beverage Mart = new Beverage("Martini", 2.5, 127, 7.00);
		// Pina Colada
		Beverage PandC = new Beverage("Pina Colada", 3.0, 440, 6.00);
		// ScrewDriver
		Beverage Sdriver = new Beverage("Screwdriver", 2.0, 181, 7.00);
		// Vodka and Tonic
		Beverage VandT = new Beverage("Voka and Tonic", 2.0, 200, 6.00);
		// Water
		Beverage water = new Beverage();

		// ArrayList for summary
		ArrayList<Beverage> list = new ArrayList<Beverage>();

		// Total bill
		double bill = 0;
		// Total calories
		double totalCal = 0;
		// Total Ounces
		double totalOunces = 0;

		System.out.print("Welcome to the EBAC Calculator!");
		System.out.println("Please enter your weight to the nearest pound");
		int UserWeight = scnr.nextInt();

		int Input = 0;

		while (Input != -1) {
			System.out.println("Please enter the number of the item you would like to drink: (-1 to exit)");
			System.out.println("0) " + BandW.toString());
			System.out.println("1) " + Cosmo.toString());
			System.out.println("2) " + GandT.toString());
			System.out.println("3) " + Moj.toString());
			System.out.println("4) " + Marg.toString());
			System.out.println("5) " + Mart.toString());
			System.out.println("6) " + PandC.toString());
			System.out.println("7) " + Sdriver.toString());
			System.out.println("8) " + VandT.toString());
			System.out.println("9) " + water.toString());
			Input = scnr.nextInt();

			if (Input == 0) {
				list.add(BandW);
			}

			if (Input == 1) {
				list.add(Cosmo);
			}
			if (Input == 2) {
				list.add(GandT);
			}
			if (Input == 3) {
				list.add(Moj);
			}
			if (Input == 4) {
				list.add(Marg);
			}
			if (Input == 5) {
				list.add(Mart);
			}
			if (Input == 6) {
				list.add(PandC);
			}
			if (Input == 7) {
				list.add(Sdriver);
			}
			if (Input == 8) {
				list.add(VandT);
			}
			if (Input == 9) {
				list.add(water);
			}

		}
		// Displays summary
		System.out.println("You had the following drinks tonight:");

		for (int i = 0; i < list.size(); i++) {

			totalOunces += list.get(i).getAlcoholContent();
			bill += list.get(i).getCost();
			totalCal += list.get(i).getCalorieCount();

			System.out.println(list.get(i).toSummary());

		}
		// Ebac calculations

		double Ebac = totalOunces * 5.14 / (UserWeight * 0.7);

		System.out.println("Your bill for the night is: $" + bill);
		System.out.println("You have consume " + totalCal + " calories.");
		System.out.println("Your final EBAC is " + Ebac);
		System.out.println("It will be " + totalOunces + " hours until you are sober again");
		System.out.println("Good night!");
	}

}

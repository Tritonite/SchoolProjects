import java.util.Scanner;

public class Project2_TristonLuzanta {
	public static void main(String[] args) {

		Scanner scn = new Scanner(System.in);

		int Shapes;
		int Calc = 0;
		int Calc2 = 0;
		int Calc3 = 0;

		Double Pi = 3.1;

		System.out.println("Welcome to the Shape Calculator!");

		System.out.println("What shape do you have?");

		System.out.println("1) A Sphere");

		System.out.println("2) A Rectangular Solid");

		System.out.println("3) A Cylinder");

		Shapes = scn.nextInt();

		// User input for what shape they have selected.

		if (Shapes == 1) {
			System.out.println("Which calculation would you like?");
			System.out.println("1) Volume");
			System.out.println("2) Surface Area");
			Calc = scn.nextInt();
			// Takes inputs and calculates volume or surface area.
		}

		if (Calc == 1) {
			System.out.println("Input the radius");
			double r = scn.nextDouble();
			// takes your radius input
			double Vol = (4.0 / 3.0 * Pi * r * r * r);
			// takes your radius input and implements it into this formula to get your
			// volume.
			System.out.println("The volume is " + Vol);
		}

		else if (Calc == 2) {
			System.out.println("Input the radius");
			double r = scn.nextDouble();
			double SA = (4.0 * Pi * r * r);
			System.out.println("The surface area is " + SA);

		}

		if (Shapes == 2) {
			System.out.println("Which calculation would you like?");
			System.out.println("1) Volume");
			System.out.println("2) Surface Area");
			Calc2 = scn.nextInt();

		}

		if (Calc2 == 1) {
			System.out.println("Input the length");
			double l = scn.nextDouble();
			System.out.println("input the width");
			double w = scn.nextDouble();
			System.out.println("Input the height");
			double h = scn.nextDouble();
			double Vol = (l * w * h);
			System.out.println("The volume is " + Vol);
		}

		else if (Calc2 == 2) {
			System.out.println("Input the length");
			double l = scn.nextDouble();
			System.out.println("input the width");
			double w = scn.nextDouble();
			System.out.println("Input the height");
			double h = scn.nextDouble();
			double SA = 2.0 * (l * h + l * w + w * h);
			System.out.println("The surface area is " + SA);
		}

		if (Shapes == 3) {
			System.out.println("Which calculation would you like?");
			System.out.println("1) Volume");
			System.out.println("2) Surface Area");
			Calc3 = scn.nextInt();

		}

		if (Calc3 == 1) {
			System.out.println("Input the radius ");
			double r = scn.nextDouble();
			System.out.println("Input the height ");
			double h = scn.nextDouble();
			double Vol = (Pi * r * r * h);
			System.out.println("The volume is " + Vol);

		}

		else if (Calc3 == 2) {
			System.out.println("Input the radius ");
			double r = scn.nextDouble();
			System.out.println("Input the height ");
			double h = scn.nextDouble();
			double SA = (2.0 * Pi * r * r) + (2.0 * Pi * r * h);
			System.out.println("The surface area is " + SA);

		}
		System.out.println("Good-bye!");

	}

}

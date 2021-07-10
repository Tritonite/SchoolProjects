/**
 * The Beverage Class contains four data elements: the name of the Beverage, the
 * alcohol content, the calorie content, and the cost. The class has a toString
 * method and a toSummary method which must be written by as part of the
 * project.
 * 
 * @author Sarah Wu, University of Oklahoma, CS 1323 Spring 2018
 */
public class Beverage {

	/**
	 * Method to print a short summary of this Beverage. For example: "Water ($0.0)"
	 * 
	 * @return the String representation of this object
	 */
	public String toString() {
		// TODO: Write this method
		String beverage = name + " ($" + cost + ")";
		return beverage;
	}

	/**
	 * Method to print a detailed summary of this Beverage. For example: "Water 0 oz
	 * 0 cal $0.0"
	 * 
	 * @return the String representation of this object
	 */
	public String toSummary() {
		// TODO: Write this method
		String Summary = name + " " + alcoholContent + " oz " + calorieCount + " cal " + " $" + cost;
		return Summary;
	}

	// Private Data Fields ---------------------------
	private String name;
	private double alcoholContent;
	private int calorieCount;
	private double cost;
	private String test;
	// -----------------------------------------------

	// Constructors ++++++++++++++++++++++++++++++++++
	/**
	 * Default Constructor
	 */
	public Beverage() {
		name = "Water";
		alcoholContent = 0;
		calorieCount = 0;
		cost = 0.0;
	}

	/**
	 * Explicit Constructor
	 * 
	 * @param name
	 *            the name to set
	 * @param alcoholContent
	 *            the alcoholContent to set
	 * @param calorieCount
	 *            the calorieCount to set
	 * @param cost
	 *            the cost to set
	 */
	public Beverage(String name, double alcoholContent, int calorieCount, double cost) {
		this.name = name;
		this.alcoholContent = alcoholContent;
		this.calorieCount = calorieCount;
		this.cost = cost;
	}
	// ++++++++++++++++++++++++++++++++++++++++++++++++++

	// Setters and Getters ==============================
	/**
	 * @return the name
	 */
	public String getName() {
		return name;
	}

	/**
	 * @param name
	 *            the name to set
	 */
	public void setName(String name) {
		this.name = name;
	}

	/**
	 * @return the alcoholContent
	 */
	public double getAlcoholContent() {
		return alcoholContent;
	}

	/**
	 * @param alcoholContent
	 *            the alcoholContent to set
	 */
	public void setAlcoholContent(double alcoholContent) {
		this.alcoholContent = alcoholContent;
	}

	/**
	 * @return the calorieCount
	 */
	public int getCalorieCount() {
		return calorieCount;
	}

	/**
	 * @param calorieCount
	 *            the calorieCount to set
	 */
	public void setCalorieCount(int calorieCount) {
		this.calorieCount = calorieCount;
	}

	/**
	 * @return the cost
	 */
	public double getCost() {
		return cost;
	}

	/**
	 * @param cost
	 *            the cost to set
	 */
	public void setCost(double cost) {
		this.cost = cost;
	}
	// =======================================================

}

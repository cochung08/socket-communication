public class AP {
	

	private String MAC;

	private int Power;

	private int Channel;

	

	public String getMAC() {
		return MAC;
	}

	public int getChannel() {
		return Channel;

	}

	public int getPower() {
		return Power;

	}

	public AP() {

	}

	public AP( String mac, int chan, int power) {
		
		MAC = mac;
		Channel = chan;
		Power = power;
	}

	public AP( String mac, String chan, String power) {
		
		MAC = mac;
		Channel = Integer.parseInt(chan);
		Power = Integer.parseInt(power);
	}

}

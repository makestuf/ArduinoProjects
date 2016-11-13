using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO.Ports;
using System.Threading;

namespace SerialCommunication
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{

		#region Variáveis
		SerialPort serial = new SerialPort();
		#endregion

		public MainWindow()
		{
			InitializeComponent();
		}

		private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
		{
			//Configurações da porta serial
			serial.Handshake = System.IO.Ports.Handshake.None;
			serial.Parity = Parity.None;
			serial.DataBits = 8;
			serial.StopBits = StopBits.One;
			serial.ReadTimeout = 200;
			serial.WriteTimeout = 50;
		}

		private void Button_Click(object sender, RoutedEventArgs e)
		{
			//Conexão com a porta serial
			if (!serial.IsOpen)
			{
				serial.PortName = commPort.Text;
				serial.BaudRate = Convert.ToInt32(commBaud.Text);
				serial.Open();
			}

			try
			{
				byte[] hexstring = Encoding.ASCII.GetBytes(textToSend.Text);
				foreach (byte hexval in hexstring)
				{
					byte[] _hexval = new byte[] { hexval }; // need to convert byte to byte[] to write
					serial.Write(_hexval, 0, 1);
					Thread.Sleep(1);
				}
			}
			catch (Exception ex)
			{
				//Exibe erro
			}

		}
	}
}

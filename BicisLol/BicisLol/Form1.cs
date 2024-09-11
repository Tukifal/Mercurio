using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BicisLol
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e) //En caso de recibir datos al puerto serial
        {
            try
            {
                // Lee los datos como una cadena
                String serialData = serialPort1.ReadLine();

                // Convierte la cadena a un número
                int data = int.Parse(serialData);

                // Ahora puedes comparar el valor numérico
                if (data == 90)
                {
                    label1.BackColor = Color.Red;
                } else if (data == 09) {
                    label1.BackColor = Color.Lime;
                }
                
                if (data == 20)
                {
                    label2.BackColor = Color.Red;
                } else if (data == 02) { 
                     label2.BackColor= Color.Lime;  
                }

                if (data == 30)
                {
                    label3.BackColor = Color.Red;
                } else if (data == 03){
                    label3.BackColor = Color.Lime;
                }

                if (data == 40)
                {
                    label4.BackColor = Color.Red;
                } else if (data == 04){
                 label4.BackColor = Color.Lime;
                }

                if (data == 50)
                {
                    label5.BackColor = Color.Red;
                } else if (data == 05){
                    label5.BackColor = Color.Lime;
                }

                if(data == 60)
                {
                label6.BackColor = Color.Red;
                }
                else if (data == 06)
                {
                label6.BackColor = Color.Lime;
                }

                if (data == 100)
                {
                    label7.ForeColor = Color.Black;
                    label7.BackColor = Color.Red;
                } else if (data == 001)
                {
                    label7.BackColor = Color.Transparent;
                    label7.ForeColor = Color. Yellow;
                }

                if (data == 202)
                {
                    label8.ForeColor = Color.Black;
                    label8.BackColor = Color.Red;
                } else if(data == 123)
                {
                    label8.BackColor = Color.Transparent;
                    label8.ForeColor = Color.Yellow;
                }

            }
            catch (FormatException)
            {
            }
        }

        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


        private void button1_Click(object sender, EventArgs e) //para conectarse al puerto serial
        {
            try
            {
                serialPort1.Open();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }
    }
}

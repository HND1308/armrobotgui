using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;


namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        
        }
        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            angle1_value.Text = trackBar1.Value.ToString();
        }

        private void trackBar2_Scroll(object sender, EventArgs e)
        {
            angle2_value.Text = trackBar2.Value.ToString();
        }

        private void trackBar3_Scroll(object sender, EventArgs e)
        {
            angle3_value.Text = trackBar3.Value.ToString();
        }

        private void trackBar4_Scroll(object sender, EventArgs e)
        {
            angle4_value.Text = trackBar4.Value.ToString();
        }

        private void trackBar5_Scroll(object sender, EventArgs e)
        {
            angle5_value.Text = trackBar5.Value.ToString();
        }

        private void trackBar6_Scroll(object sender, EventArgs e)
        {
            angle6_value.Text = trackBar6.Value.ToString();
        }

        private void connect_btn_CheckedChanged(object sender, EventArgs e)
        {
            if (connect_btn.Checked) 
            {
                try
                {
                    if (!serialPort1.IsOpen)
                        serialPort1.Open();

                    MessageBox.Show("Connected successfully!");
                    confirm_btn.Enabled = serialPort1.IsOpen;
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error connecting to serial port: " + ex.Message);
                }
            }
        }

        private void disconnect_btn_CheckedChanged(object sender, EventArgs e)
        {
            if (disconnect_btn.Checked) 
            {
                try
                {
                    if (serialPort1.IsOpen)
                        serialPort1.Close();

                    MessageBox.Show("Disconnected successfully!");
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error disconnecting: " + ex.Message);
                }
            }
        }
        bool confirmBtn = false;
        private void confirm_btn_Click(object sender, EventArgs e)
        {
            confirmBtn = true;
            if (connect_btn.Checked && serialPort1.IsOpen)
            {
                try
                {
                    int[] data = new int[6];
                    data[0] = trackBar1.Value;
                    data[1] = trackBar2.Value;
                    data[2] = trackBar3.Value;
                    data[3] = trackBar4.Value;
                    data[4] = trackBar5.Value;
                    data[5] = trackBar6.Value;

                    string result = string.Join(",", data);
                    serialPort1.Write(result + "\n"); 
                    MessageBox.Show("Data sent: " + result);
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error sending data: " + ex.Message);
                }
            }
            else
            {
                MessageBox.Show("Please connect to the device before sending data!");
            }
        }

        List<int[]> recordedMove = new List<int[]>();
        bool isRecording;

        private void record_btn_Click(object sender, EventArgs e)
        {
            recordedMove.Clear();
            isRecording = true;
        }

        private void stop_btn_Click(object sender, EventArgs e)
        {
            isRecording = false;
            serialPort1.Write("RecordMode" + "\n");
            string data = string.Join(";", recordedMove.Select(arr => string.Join(",", arr)));
            serialPort1.Write(data + "\n");
        }

        private void update_Angle_Record()
        {
            if (isRecording)
            {
                if (confirmBtn)
                {
                    int[] currentAngle = { trackBar1.Value, trackBar2.Value, trackBar3.Value, trackBar4.Value, trackBar5.Value, trackBar6.Value };
                    recordedMove.Add(currentAngle);
                }
            }
        }
    }
}

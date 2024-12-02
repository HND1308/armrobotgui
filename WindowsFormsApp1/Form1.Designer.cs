namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.trackBar1 = new System.Windows.Forms.TrackBar();
            this.trackBar2 = new System.Windows.Forms.TrackBar();
            this.trackBar3 = new System.Windows.Forms.TrackBar();
            this.trackBar4 = new System.Windows.Forms.TrackBar();
            this.trackBar5 = new System.Windows.Forms.TrackBar();
            this.trackBar6 = new System.Windows.Forms.TrackBar();
            this.confirm_btn = new System.Windows.Forms.Button();
            this.angle1_value = new System.Windows.Forms.Label();
            this.angle2_value = new System.Windows.Forms.Label();
            this.angle3_value = new System.Windows.Forms.Label();
            this.angle4_value = new System.Windows.Forms.Label();
            this.angle5_value = new System.Windows.Forms.Label();
            this.angle6_value = new System.Windows.Forms.Label();
            this.connect_btn = new System.Windows.Forms.RadioButton();
            this.disconnect_btn = new System.Windows.Forms.RadioButton();
            this.label1 = new System.Windows.Forms.Label();
            this.record_btn = new System.Windows.Forms.Button();
            this.stop_btn = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar6)).BeginInit();
            this.SuspendLayout();
            // 
            // serialPort1
            // 
            this.serialPort1.PortName = "COM4";
            // 
            // trackBar1
            // 
            this.trackBar1.Location = new System.Drawing.Point(75, 143);
            this.trackBar1.Maximum = 180;
            this.trackBar1.Name = "trackBar1";
            this.trackBar1.Size = new System.Drawing.Size(104, 56);
            this.trackBar1.TabIndex = 0;
            this.trackBar1.Scroll += new System.EventHandler(this.trackBar1_Scroll);
            // 
            // trackBar2
            // 
            this.trackBar2.Location = new System.Drawing.Point(346, 143);
            this.trackBar2.Maximum = 180;
            this.trackBar2.Minimum = 120;
            this.trackBar2.Name = "trackBar2";
            this.trackBar2.Size = new System.Drawing.Size(104, 56);
            this.trackBar2.TabIndex = 1;
            this.trackBar2.Value = 120;
            this.trackBar2.Scroll += new System.EventHandler(this.trackBar2_Scroll);
            // 
            // trackBar3
            // 
            this.trackBar3.Location = new System.Drawing.Point(75, 223);
            this.trackBar3.Maximum = 120;
            this.trackBar3.Name = "trackBar3";
            this.trackBar3.Size = new System.Drawing.Size(104, 56);
            this.trackBar3.TabIndex = 2;
            this.trackBar3.Scroll += new System.EventHandler(this.trackBar3_Scroll);
            // 
            // trackBar4
            // 
            this.trackBar4.Location = new System.Drawing.Point(346, 223);
            this.trackBar4.Maximum = 180;
            this.trackBar4.Minimum = 90;
            this.trackBar4.Name = "trackBar4";
            this.trackBar4.Size = new System.Drawing.Size(104, 56);
            this.trackBar4.TabIndex = 3;
            this.trackBar4.Value = 90;
            this.trackBar4.Scroll += new System.EventHandler(this.trackBar4_Scroll);
            // 
            // trackBar5
            // 
            this.trackBar5.Location = new System.Drawing.Point(75, 301);
            this.trackBar5.Maximum = 180;
            this.trackBar5.Name = "trackBar5";
            this.trackBar5.Size = new System.Drawing.Size(104, 56);
            this.trackBar5.TabIndex = 4;
            this.trackBar5.Scroll += new System.EventHandler(this.trackBar5_Scroll);
            // 
            // trackBar6
            // 
            this.trackBar6.Location = new System.Drawing.Point(346, 301);
            this.trackBar6.Maximum = 120;
            this.trackBar6.Minimum = 30;
            this.trackBar6.Name = "trackBar6";
            this.trackBar6.Size = new System.Drawing.Size(104, 56);
            this.trackBar6.TabIndex = 5;
            this.trackBar6.Value = 30;
            this.trackBar6.Scroll += new System.EventHandler(this.trackBar6_Scroll);
            // 
            // confirm_btn
            // 
            this.confirm_btn.Location = new System.Drawing.Point(573, 223);
            this.confirm_btn.Name = "confirm_btn";
            this.confirm_btn.Size = new System.Drawing.Size(103, 45);
            this.confirm_btn.TabIndex = 8;
            this.confirm_btn.Text = "Truyền";
            this.confirm_btn.UseVisualStyleBackColor = true;
            this.confirm_btn.Click += new System.EventHandler(this.confirm_btn_Click);
            // 
            // angle1_value
            // 
            this.angle1_value.AutoSize = true;
            this.angle1_value.Location = new System.Drawing.Point(185, 150);
            this.angle1_value.Name = "angle1_value";
            this.angle1_value.Size = new System.Drawing.Size(48, 16);
            this.angle1_value.TabIndex = 9;
            this.angle1_value.Text = "angle1";
            // 
            // angle2_value
            // 
            this.angle2_value.AutoSize = true;
            this.angle2_value.Location = new System.Drawing.Point(456, 150);
            this.angle2_value.Name = "angle2_value";
            this.angle2_value.Size = new System.Drawing.Size(48, 16);
            this.angle2_value.TabIndex = 10;
            this.angle2_value.Text = "angle2";
            // 
            // angle3_value
            // 
            this.angle3_value.AutoSize = true;
            this.angle3_value.Location = new System.Drawing.Point(185, 228);
            this.angle3_value.Name = "angle3_value";
            this.angle3_value.Size = new System.Drawing.Size(48, 16);
            this.angle3_value.TabIndex = 11;
            this.angle3_value.Text = "angle3";
            // 
            // angle4_value
            // 
            this.angle4_value.AutoSize = true;
            this.angle4_value.Location = new System.Drawing.Point(456, 228);
            this.angle4_value.Name = "angle4_value";
            this.angle4_value.Size = new System.Drawing.Size(48, 16);
            this.angle4_value.TabIndex = 12;
            this.angle4_value.Text = "angle4";
            // 
            // angle5_value
            // 
            this.angle5_value.AutoSize = true;
            this.angle5_value.Location = new System.Drawing.Point(185, 311);
            this.angle5_value.Name = "angle5_value";
            this.angle5_value.Size = new System.Drawing.Size(48, 16);
            this.angle5_value.TabIndex = 13;
            this.angle5_value.Text = "angle5";
            // 
            // angle6_value
            // 
            this.angle6_value.AutoSize = true;
            this.angle6_value.Location = new System.Drawing.Point(456, 311);
            this.angle6_value.Name = "angle6_value";
            this.angle6_value.Size = new System.Drawing.Size(48, 16);
            this.angle6_value.TabIndex = 14;
            this.angle6_value.Text = "angle6";
            // 
            // connect_btn
            // 
            this.connect_btn.AutoSize = true;
            this.connect_btn.Location = new System.Drawing.Point(177, 46);
            this.connect_btn.Name = "connect_btn";
            this.connect_btn.Size = new System.Drawing.Size(75, 20);
            this.connect_btn.TabIndex = 15;
            this.connect_btn.TabStop = true;
            this.connect_btn.Text = "connect";
            this.connect_btn.UseVisualStyleBackColor = true;
            this.connect_btn.CheckedChanged += new System.EventHandler(this.connect_btn_CheckedChanged);
            // 
            // disconnect_btn
            // 
            this.disconnect_btn.AutoSize = true;
            this.disconnect_btn.Location = new System.Drawing.Point(177, 72);
            this.disconnect_btn.Name = "disconnect_btn";
            this.disconnect_btn.Size = new System.Drawing.Size(93, 20);
            this.disconnect_btn.TabIndex = 16;
            this.disconnect_btn.TabStop = true;
            this.disconnect_btn.Text = "disconnect";
            this.disconnect_btn.UseVisualStyleBackColor = true;
            this.disconnect_btn.CheckedChanged += new System.EventHandler(this.disconnect_btn_CheckedChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(105, 62);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(47, 16);
            this.label1.TabIndex = 17;
            this.label1.Text = "Kết nối";
            // 
            // record_btn
            // 
            this.record_btn.Location = new System.Drawing.Point(519, 46);
            this.record_btn.Name = "record_btn";
            this.record_btn.Size = new System.Drawing.Size(103, 32);
            this.record_btn.TabIndex = 18;
            this.record_btn.Text = "Record";
            this.record_btn.UseVisualStyleBackColor = true;
            this.record_btn.Click += new System.EventHandler(this.record_btn_Click);
            // 
            // stop_btn
            // 
            this.stop_btn.Location = new System.Drawing.Point(655, 46);
            this.stop_btn.Name = "stop_btn";
            this.stop_btn.Size = new System.Drawing.Size(103, 32);
            this.stop_btn.TabIndex = 19;
            this.stop_btn.Text = "Stop Record";
            this.stop_btn.UseVisualStyleBackColor = true;
            this.stop_btn.Click += new System.EventHandler(this.stop_btn_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.stop_btn);
            this.Controls.Add(this.record_btn);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.disconnect_btn);
            this.Controls.Add(this.connect_btn);
            this.Controls.Add(this.angle6_value);
            this.Controls.Add(this.angle5_value);
            this.Controls.Add(this.angle4_value);
            this.Controls.Add(this.angle3_value);
            this.Controls.Add(this.angle2_value);
            this.Controls.Add(this.angle1_value);
            this.Controls.Add(this.confirm_btn);
            this.Controls.Add(this.trackBar6);
            this.Controls.Add(this.trackBar5);
            this.Controls.Add(this.trackBar4);
            this.Controls.Add(this.trackBar3);
            this.Controls.Add(this.trackBar2);
            this.Controls.Add(this.trackBar1);
            this.Name = "Form1";
            this.Text = "Controller";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar6)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.TrackBar trackBar1;
        private System.Windows.Forms.TrackBar trackBar2;
        private System.Windows.Forms.TrackBar trackBar3;
        private System.Windows.Forms.TrackBar trackBar4;
        private System.Windows.Forms.TrackBar trackBar5;
        private System.Windows.Forms.TrackBar trackBar6;
        private System.Windows.Forms.Button confirm_btn;
        private System.Windows.Forms.Label angle1_value;
        private System.Windows.Forms.Label angle2_value;
        private System.Windows.Forms.Label angle3_value;
        private System.Windows.Forms.Label angle4_value;
        private System.Windows.Forms.Label angle5_value;
        private System.Windows.Forms.Label angle6_value;
        private System.Windows.Forms.RadioButton connect_btn;
        private System.Windows.Forms.RadioButton disconnect_btn;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button record_btn;
        private System.Windows.Forms.Button stop_btn;
    }
}


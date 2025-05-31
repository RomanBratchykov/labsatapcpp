using System;
using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Threading;

namespace HomeworkGUI2
{
    public enum DeviceType { Watch, Phone, Headphones };
    public enum PowerSavingMode { A, AA, AAA };
    public class Device
    {
        public string Name { get; set; }
        public DeviceType Type { get; set; }
        public int BatteryLevel { get; set; }
        public PowerSavingMode Mode { get; set; }

        public Device(string name, DeviceType type, int batteryLevel, PowerSavingMode mode)
        {
            Name = name;
            Type = type;
            BatteryLevel = batteryLevel;
            Mode = mode;
        }
    }

    public class SmartDevice : Device
    {
        public SmartDevice(string name, DeviceType type, int batteryLevel, PowerSavingMode mode)
            : base(name, type, batteryLevel, mode) { }
    }


    public partial class MainWindow : Window
    {
        private List<Device> devices = new List<Device>();
        private DispatcherTimer timer;
        private double textPosition = 0;
        private bool movingRight = true;

        public MainWindow()
        {
            InitializeComponent();

            DeviceTypeInput.ItemsSource = Enum.GetValues(typeof(DeviceType));

            DeviceGrid.ItemsSource = devices;

            timer = new DispatcherTimer();
            timer.Interval = TimeSpan.FromMilliseconds(50);
            timer.Tick += Timer_Tick;
            timer.Start();

            Closing += Window_Closing;
        }

        private void AddDevice_Click(object sender, RoutedEventArgs e)
        {
            if (string.IsNullOrWhiteSpace(DeviceNameInput.Text) || DeviceTypeInput.SelectedItem == null)
            {
                MessageBox.Show("Please enter a device name and select a type.");
                return;
            }

            DeviceType type = (DeviceType)DeviceTypeInput.SelectedItem;


            Device device = new Random().Next(2) == 0
                ? new Device(DeviceNameInput.Text, type, new Random().Next(0, 101), PowerSavingMode.A)
                : new SmartDevice(DeviceNameInput.Text, type, new Random().Next(0, 101), PowerSavingMode.AA);

            devices.Add(device);
            DeviceGrid.Items.Refresh();
            DeviceNameInput.Clear();
            DeviceTypeInput.SelectedIndex = -1;
        }

        private void ChargeDevice_Click(object sender, RoutedEventArgs e)
        {
            string name = DeviceNameInput.Text;
            var device = devices.Find(d => d.Name == name);
            if (device != null)
            {
                device.BatteryLevel = 100;
                DeviceGrid.Items.Refresh();
                if (DeviceGrid.SelectedItem == device)
                    BatteryProgressBar.Value = 100;
            }
            else
            {
                MessageBox.Show("Device not found.");
            }
        }

        private void DeviceGrid_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (DeviceGrid.SelectedItem is Device selectedDevice)
            {
                BatteryProgressBar.Value = selectedDevice.BatteryLevel;
            }
            else
            {
                BatteryProgressBar.Value = 0;
            }
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            double canvasWidth = TextCanvas.ActualWidth;
            double textWidth = ScrollingText.ActualWidth;

            if (canvasWidth == 0 || textWidth == 0) return;

            if (movingRight)
            {
                textPosition += 2;
                if (textPosition + textWidth > canvasWidth)
                {
                    movingRight = false;
                }
            }
            else
            {
                textPosition -= 2;
                if (textPosition < 0)
                {
                    movingRight = true;
                }
            }

            Canvas.SetLeft(ScrollingText, textPosition);
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            string message = "Devices with battery > 80%:\n";
            bool found = false;
            foreach (var device in devices)
            {
                if (device.BatteryLevel > 80)
                {
                    message += $"{device.Name}: {device.BatteryLevel}%\n";
                    found = true;
                }
            }
            if (!found)
                message += "None";
            MessageBox.Show(message);
        }

        private void ExitButton_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
    }

}
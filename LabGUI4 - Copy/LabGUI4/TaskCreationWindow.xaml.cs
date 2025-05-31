using System;
using System.Windows;
using System.Windows.Controls;

namespace LabGUI4
{
    public partial class TaskCreationWindow : Window
    {
        public Task? CreatedTask { get; private set; }

        public TaskCreationWindow()
        {
            InitializeComponent();
        }

        private void HasDeadlineCheckBox_Checked(object sender, RoutedEventArgs e)
        {
            DeadlineLabel.Visibility = Visibility.Visible;
            DatePickerDeadline.Visibility = Visibility.Visible;
        }

        private void HasDeadlineCheckBox_Unchecked(object sender, RoutedEventArgs e)
        {
            DeadlineLabel.Visibility = Visibility.Collapsed;
            DatePickerDeadline.Visibility = Visibility.Collapsed;
        }

    private void OKButton_Click(object sender, RoutedEventArgs e)
        {
            if (string.IsNullOrWhiteSpace(NameTextBox.Text) ||
                PriorityComboBox.SelectedItem == null ||
                StatusComboBox.SelectedItem == null ||
                DatePickerStart.SelectedDate == null)
            {
                MessageBox.Show("Please fill all fields correctly!");
                return;
            }

            var startDate = DatePickerStart.SelectedDate.Value;
            var priority = (Priority)Enum.Parse(typeof(Priority), (PriorityComboBox.SelectedItem as ComboBoxItem)?.Content?.ToString());
            var status = (Status)Enum.Parse(typeof(Status), (StatusComboBox.SelectedItem as ComboBoxItem)?.Content?.ToString());

            if (HasDeadlineCheckBox.IsChecked == true)
            {
                if (DatePickerDeadline.SelectedDate == null)
                {
                    MessageBox.Show("Please select deadline date!");
                    return;
                }

                var deadlineDate = DatePickerDeadline.SelectedDate.Value;

                if (deadlineDate <= startDate)
                {
                    MessageBox.Show("Deadline must be after start date!");
                    return;
                }

                CreatedTask = new TaskWithDeadline(
                    NameTextBox.Text,
                    priority,
                    status,
                    startDate.Day, startDate.Month,
                    deadlineDate.Day, deadlineDate.Month
                );
            }
            else
            {
                CreatedTask = new Task(
                    NameTextBox.Text,
                    priority,
                    status,
                    startDate.Day, startDate.Month
                );
            }

            DialogResult = true;
            Close();
        }
        private void CancelButton_Click(object sender, RoutedEventArgs e)
        {
            DialogResult = false;
            Close();
        }
    }
}
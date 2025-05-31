using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Threading;
using System.Collections.ObjectModel;

namespace LabGUI4
{
    public partial class MainWindow : Window
    {
        private ObservableCollection<Task> tasks = new ObservableCollection<Task>();
        private DispatcherTimer timer;
        private DispatcherTimer? timer2;
        private bool moveRight = true;
        private double labelPosition = 0;
        public DateTime fromDate;

        public MainWindow()
        {
            InitializeComponent();
            TasksGrid.ItemsSource = tasks;
            timer = new DispatcherTimer();
            timer.Interval = TimeSpan.FromSeconds(1);
            timer.Tick += Timer_Tick;
            timer.Start();
        }

        private void Timer_Tick(object? sender, EventArgs e)
        {
            labelPosition += moveRight ? 5 : -5;
            if (labelPosition > ActualWidth - 150) moveRight = false;
            if (labelPosition < 0) moveRight = true;
            AnimatedLabel.Margin = new Thickness(labelPosition, 0, 0, 0);

            foreach (var item in tasks.OfType<TaskWithDeadline>())
            {
                item.UpdateProgress();
            }
        }
        private void Timer2_Tick(object? sender, EventArgs e)
        {
            foreach (var item in tasks.OfType<TaskWithDeadline>())
            {
                item.UpdateProgress();
            }
        }

        private void AddTask_Click(object sender, RoutedEventArgs e)
        {
            var taskWindow = new TaskCreationWindow();
            if (taskWindow.ShowDialog() == true && taskWindow.CreatedTask != null)
            {
                tasks.Add(taskWindow.CreatedTask);
                timer2 = new DispatcherTimer();
                timer2.Interval = TimeSpan.FromSeconds(1);
                timer2.Start();
                timer2.Tick += Timer2_Tick;
                fromDate = DateTime.Now;
                TasksGrid.Items.Refresh();
            }
        }

        private void MarkCompleted_Click(object sender, RoutedEventArgs e)
        {
            if (TasksGrid.SelectedItem is Task selectedTask)
            {
                selectedTask.Status = Status.Completed;
                if (selectedTask is TaskWithDeadline taskWithDeadline)
                {
                    taskWithDeadline.UpdateProgress();
                }
                TasksGrid.Items.Refresh();
            }
        }

        private void ChangeDeadline_Click(object sender, RoutedEventArgs e)
        {
            if (TasksGrid.SelectedItem is TaskWithDeadline selectedTask)
            {
                var input = Microsoft.VisualBasic.Interaction.InputBox("Введіть новий дедлайн (дд.мм):", "Зміна дедлайну", "");
                if (TryParseDate(input, out int day, out int month))
                {
                    selectedTask.Deadline = new DateTime(DateTime.Now.Year, month, day);
                    selectedTask.UpdateProgress();
                    TasksGrid.Items.Refresh();
                }
                else
                {
                    MessageBox.Show("Неправильний формат дати!");
                }
            }
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            var incompleteTasks = tasks.Where(t => t.Status != Status.Completed)
                                      .Select(t => t.Name);
            if (incompleteTasks.Any())
            {
                MessageBox.Show("Невіконані завдання:\n" + string.Join("\n", incompleteTasks), "Менеджер завдань");
            }
        }

        private bool TryParseDate(string input, out int day, out int month)
        {
            day = month = 0;
            if (input.Length == 5 && input[2] == '.')
            {
                if (int.TryParse(input.Substring(0, 2), out day) && int.TryParse(input.Substring(3, 2), out month))
                {
                    return day >= 1 && day <= 31 && month >= 1 && month <= 12;
                }
            }
            return false;
        }

        private void Exit_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
    }
}
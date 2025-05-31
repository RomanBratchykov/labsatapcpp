using System;
using System.ComponentModel;

namespace LabGUI4
{
    public class TaskWithDeadline : Task, INotifyPropertyChanged
    {
        private DateTime deadline;
        private TimeSpan timeRemaining;
        private double progress;
        private string timeRemainingDisplay;
        public DateTime Deadline
        {
            get => deadline;
            set
            {
                deadline = value;
                OnPropertyChanged(nameof(Deadline));
                UpdateTimeRemaining();
                UpdateProgress();
            }
        }

        public TimeSpan TimeRemaining
        {
            get => timeRemaining;
            set
            {
                timeRemaining = value;
                OnPropertyChanged(nameof(timeRemaining));
            }
        }

        public string TimeRemainingDisplay
        {
            get
            {
                if (TimeRemaining.TotalSeconds <= 0)
                    return "00h 00m 00s";
                return $"{(TimeRemaining.Hours + (TimeRemaining.Days * 24)):D2}h {TimeRemaining.Minutes:D2}m {TimeRemaining.Seconds:D2}s";
            }
        }


        public double Progress
        {
            get => progress;
            set
            {
                progress = value;
                OnPropertyChanged(nameof(Progress));
            }
        }

        public TaskWithDeadline(string name, Priority priority, Status status, int startDay, int startMonth, int deadlineDay, int deadlineMonth)
            : base(name, priority, status, startDay, startMonth)
        {
            PropertyChanged = delegate { };
            Deadline = new DateTime(DateTime.Now.Year, deadlineMonth, deadlineDay);
            if (Deadline < StartDate)
                throw new ArgumentException("Дедлайн не може бути раніше дати початку завдання.");
            UpdateTimeRemaining();
            UpdateProgress();
        }
        private void UpdateTimeRemaining()
        {
            var now = DateTime.Now;
            TimeRemaining = Deadline > now ? (Deadline - now) : TimeSpan.Zero;
            OnPropertyChanged(nameof(TimeRemainingDisplay));
        }

        public void UpdateProgress()
        {
            var now = DateTime.Now;
            timeRemaining = Deadline > now ? Deadline - now : TimeSpan.Zero;

            double totalSeconds = (Deadline - StartDate).TotalSeconds;
            double elapsedSeconds = (StartDate - now).TotalSeconds;

            if (totalSeconds > 0)
            {
                Progress = Math.Min(100, Math.Max(0, (elapsedSeconds / totalSeconds) * 100));
                OnPropertyChanged(nameof(Progress));
            }
            else
            {
                Progress = 0;
                OnPropertyChanged(nameof(Progress));
            }
            UpdateTimeRemaining();
        }

        public override string GetDisplayInfo()
        {
            string timeDisplay = $"{timeRemaining.Days}d {timeRemaining.Hours:D2}h {timeRemaining.Minutes:D2}m {timeRemaining.Seconds:D2}s";
            return $"{base.GetDisplayInfo()}, {Deadline:dd.MM}, {Progress:F1}%, {timeDisplay}";
        }

        public event PropertyChangedEventHandler? PropertyChanged;
        protected void OnPropertyChanged(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}
function showAlert(message, alertType) {
    const alertContainer = document.getElementById('alertContainer');
    const alertElement = document.createElement('div');
    alertElement.classList.add('alert', 'alert-dismissible', alertType);
    alertElement.innerHTML = `
        <button type="button" class="btn-close" data-bs-dismiss="alert"></button>
        <strong>${message}</strong>
    `;
    alertContainer.appendChild(alertElement);
    setTimeout(function() {
        alertContainer.removeChild(alertElement);
    }, 5000); // Remove alert after 5 seconds
}


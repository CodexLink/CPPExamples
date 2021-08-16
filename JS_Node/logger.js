var URLContext = 'http://logger.io/logger'

// ! Extending EventEmitter with Logger.js
const EventE = require('events');
//const ActualEventE = new EventE(); // ! Only used for Function Based Only

// ! EXTEND the EventEmitter : ES6
class Logger extends EventE {
    log(message, type) {
        console.log('[' + type + '] ' + message); // Send an Request — Placeholder.
        return this.emit('messageLogged', { id: 1, url: 'http://' });
    }

}

// Export Modules Function
//module.exports.log = log;

// Export Modules One Function Only
//module.exports = log;

// Export a Variable
//module.exports.url_context = URLContext;

// Export the Class
module.exports = Logger; // ! Class